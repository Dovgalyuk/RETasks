# Вариант 4

Программы были переведены в код на ассемблере с помощью команд `gcc variant4.c -O0 -gdwarf-2 -S -o O0.o` и `gcc variant4.c -O2 -gdwarf-2 -S -o O2.o`.

## Сравните получившийся код

При использовании флага O0 обязательно сохраняются локальные переменные, для чего создаётся стековый фрейм. В случае с O2, по возможности, стековый фрейм не создаётся, и операции проводятся над регистрами, в которых передаются переменные. Флаг O0 необходим для возможности построчной отладки программы
С O2 значения зануляются операцией XOR с самим собой, в то время как с O0 это достигается помещением в них 0
В функции f4 с флагом O2 компилятор организовал подобие бинарного поиска по возможным значениям и заранее помещал в регистр возврата возможный результат. С O0 он этого не сделал и напрямую проводил сравнения со всеми значениями из case от большего к меньшему. В случае совпадения происходил переход к возврату соответствующего результата, а в случае, если значение переменной больше текущего значения в case, происходил выход из switch
В функции f5, так как значения в case почти последовательные, результат вычисляется с помощью таблицы. Однако в случае с O0 таблица содержит смещение инструкций, а с O2 в ней содержатся непосредственно результаты, которые перекладываются в регистр возврата
В функции f6 с O0 после сравнения через `jne`` происходит переход к метке присвоения 26 в регистр возврата, а с O2 оба варианта возврата заносятся в свои регистры, после чего нужный перемещается в регистр возврата с помощью команды `cmovne`
В функции f7 сравнение с 0 выполняется по-разному (в O0 с помощью `cmpl $0`, а в O2 с помощью `testl`). Также с O2 значение `B` заранее помещается в регистр возврата и перезаписывается, если условие не выполняется
Функция f8 также отличается механизмом сравнения, а также тем, явно ли кладётся нужное значение из переданных аргументов в регистр возврата
В функции f9 при использовании O2 на самом деле не используется переменная `i``, и вместо этого работа идёт напрямую с адресами. Условием конца цикла является достижение конца массива
В функциях f10 и f11 с O2, если `a==0`, то возврат происходит сразу, без записи значения `rbx` на стек для восстановления


## Ответьте на вопросы по каждой функции (где они применимы):

В ответах я буду опираться на код, полученный с флагом O2

### Как передаются параметры в функции?
Ответ общий для всех функций, принимающих аргументы: они передаются в регистрах `%rdi`, `%rsi`, `%rdx`

### Как организован оператор ветвления?

#### f4

Оператор ветвления организован подобием бинарного поиска по возможным вариантам. Например, если передать число 11, будут выполнены проверки:
1) 11==1000
2) 11>1000
3) 11==6
4) 11==10
Ни одна из них не выполнится, поэтому по инструкции `jne .L17` произойдёт переход в `.L17`, где будет выполнено зануление регистра возврата и ещё одна проверка (`11==1`), которая не пройдёт.

#### f5

Так как возможные значения расположены рядом, вместо сравнений оператор ветвления работает на основе таблицы результатов. Сначала из переданного числа вычитается минимальное возможное из case (в данном случае 3), затем выполняется проверка, что результат не больше максимально возможного сдвига (тут важно учесть, что если переданный аргумент был `<3`, то при сравнении отрицательного значения с помощью cmpl мы будем рассматривать его как большое положительное число). Наконец, если результат попадает в диапазон, мы берём значение с соответствующим сдвигом из `CSWTCH.6`

#### f6

Тернарный оператор реализован с помощью сравнения, используя `cmpl`, а затем помещением необходимого результата в регистр возврата с помощью `cmovne`

#### f7

Происходит поочерёдное сравнение `a` и `c` с 0. Если сравнение выполняется, сразу же происходит переход к метке, по которой значение `b` записывается в регистр возврата. Если оба сравнения не выполняются, то переход по метке не происходит и возвращается `a`, которое ещё до сравнений кладётся в регистр возврата

#### f8

Сначала происходит сравнение `a` с 0, а затем сравнение `a` с `b`. В остальном аналогично f7

#### f11

```asm
    testl	%ebx, %ebx
    jne	.L53
```

Ничего необычного, также сравниваем значение с 0 и выполняем переход по метке, если оно выполнилось

### Как выполняется оператор цикла?

#### f9

В конце выполнения инструкций цикла происходит проверка на то, дошли ли мы до целевого адреса памяти. Если нет, то переходим на метку начала инструкций цикла

#### f10, f12

После выполнения инструкций цикла проверяем условие. Если условие выполняется, переходим на метку начала инструкций цикла. Отличаются только тем, выполняется ли проверка условия перед входом в цикл (в f12 это не делается, т.к. это цикл с постусловием)

### Как происходят обращения к массивам?

#### f9

С помощью инструкции получения эффективного адреса `leaq	t(%rip), %rax` и увеличения смещения `addq	$4, %rax`

### В каких регистрах или ячейках памяти хранятся переменные?

Общий ответ для всех функций: переменные, которые передаются в функцию, находятся в регистрах `%rdi, %rsi, %rdx`. Также для вычислений значения сохраняются в регистрах `%eax`, `%edi`. Таблица значений для возврата из f5 хранится в `CSWTCH.6` в области данных. Там же резервируется память для глобальных массивов `t` и `s`