# auth_overflow

Входные данные: `1234567890123456AAAAAAAAAAAAA`
Интуиция подсказывала, что должно подойти и `1234567890123456A`, но после дизасемблирования с помощью Ghidra оказалось, что в массие выделяется место под 28 элементов

# auth_overlow2

gdb ...
break check_...
info registers(to get sp)
step next
abcde
look at our adress
info registers(to get sp(for fun))
x/64bx first sp adress
replace curr line adress with (print &granted adress)