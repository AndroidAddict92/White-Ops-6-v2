namespace BO6 {
    static uint32_t refdef = 0xCC3CB98;
    static uint32_t name_array = 0xCC859E0;
    static uint32_t name_array_pos = 0x1838;
    static uint32_t name_size = 0xC8;
    static uint32_t loot_ptr = 0x0;
    static uint32_t loot_pos = 0x170;
    static uint32_t loot_valid = 0x124;
    static uint32_t loot_valid_supply = 0x126;
    static uint32_t loot_size = 0x3E0;
    static uint32_t camera_base = 0xC809EB0;
    static uint32_t camera_pos = 0x204;
    static uint32_t local_index = 0x36C0;
    static uint32_t local_index_pos = 0x34C;
    static uint32_t recoil = 0x4FCAC;
    static uint32_t game_mode = 0xB5B3548;
    static uint32_t weapon_definitions = 0xC9D5220;
    static uint32_t distribute = 0x104AA528;
    static uint32_t visible_offset = 0x3688;
    static uint32_t visible = 0x3688;
    static uint32_t scoreboard = 0x50018;
    static uint32_t scoreboard_size = 0x90;

    namespace bone {
        static uintptr_t base_pos = 0x5B2E8;
        static uintptr_t index_struct_size = 0x1A0;
    };

    namespace player {
        static uint32_t size = 0x20B8;
        static uint32_t valid = 0x6E4;
        static uint32_t pos = 0x1270;
        static uint32_t team = 0x1280;
        static uint32_t stance = 0x9FC;
        static uint32_t weapon_index = 0x1388;
        static uint32_t dead_1 = 0x0;
        static uint32_t dead_2 = 0x0;
        static uint32_t entity_size = 0x588;
        static uint32_t entity_type = 0x410;
        static uint32_t entity_valid = 0x524;
        static uint32_t entity_index = 0x408;
        static uint32_t entity_alive = 0x42D;
        static uint32_t entity_pos = entity_type + 0x1C;
    }
}

namespace BO6 {
    uint64_t steam_decrypt_client_info(uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rdx = driver::read<uint64_t>(baseAddr + 0xCC379F8);
        if (!rdx)
            return rdx;
        rcx = peb;               //mov rcx, gs:[rax]
        rdx += 0xFFFFFFFFFFFF9357;              //add rdx, 0xFFFFFFFFFFFF9357
        rax = baseAddr;              //lea rax, [0xFFFFFFFFFA0B6D53]
        rcx -= rax;             //sub rcx, rax
        rcx += rdx;             //add rcx, rdx
        rax = rcx;              //mov rax, rcx
        rax >>= 0x1D;           //shr rax, 0x1D
        rcx ^= rax;             //xor rcx, rax
        rdx = rcx;              //mov rdx, rcx
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rdx >>= 0x3A;           //shr rdx, 0x3A
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rdx ^= rcx;             //xor rdx, rcx
        rax ^= driver::read<uint64_t>(baseAddr + 0xB3D2DEC);            //xor rax, [0x0000000005489B03]
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver::read<uint64_t>(rax + 0x15);                 //imul rdx, [rax+0x15]
        rax = 0xD67810518E7F25DD;               //mov rax, 0xD67810518E7F25DD
        rdx *= rax;             //imul rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x5;            //shr rax, 0x05
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0xA;            //shr rax, 0x0A
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x14;           //shr rax, 0x14
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x28;           //shr rax, 0x28
        rdx ^= rax;             //xor rdx, rax
        return rdx;
    }

    uint64_t steam_decrypt_client_base(uint64_t client_info, uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        r8 = driver::read<uint64_t>(client_info + 0x1d5e58);
        if (!r8)
            return r8;
        rbx = ~peb;               //mov rbx, gs:[rax]
        rax = rbx;              //mov rax, rbx
        rax = _rotl64(rax, 0x34);               //rol rax, 0x34
        rax &= 0xF;
        switch (rax) {
        case 0:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890EE69]
            r13 = baseAddr + 0x33D36DEA;                 //lea r13, [0x0000000031272DE6]
            r14 = baseAddr + 0x16CBED5E;                 //lea r14, [0x00000000141FAD4F]
            rcx = baseAddr + 0xDD05;             //lea rcx, [0xFFFFFFFFFD549C9F]
            r8 ^= rbx;              //xor r8, rbx
            r8 ^= r13;              //xor r8, r13
            rax = rbx;              //mov rax, rbx
            rax *= r14;             //imul rax, r14
            r8 -= rax;              //sub r8, rax
            rax = 0x2F44AFC8DA410289;               //mov rax, 0x2F44AFC8DA410289
            r8 *= rax;              //imul r8, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = 0x31EA6C7327F2F48F;               //mov rax, 0x31EA6C7327F2F48F
            r8 *= rax;              //imul r8, rax
            rax = rbx;              //mov rax, rbx
            rax = ~rax;             //not rax
            rax ^= rcx;             //xor rax, rcx
            r8 -= rax;              //sub r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0xF;            //shr rax, 0x0F
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x1E;           //shr rax, 0x1E
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x3C;           //shr rax, 0x3C
            r8 ^= rax;              //xor r8, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53BDCD]
            r8 -= rax;              //sub r8, rax
            return r8;
        }
        case 1:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);              //mov r9, [0x000000000890E9A4]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53B72C]
            rax += 0x4C577047;              //add rax, 0x4C577047
            rax += rbx;             //add rax, rbx
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x16;           //shr rax, 0x16
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x2C;           //shr rax, 0x2C
            r8 ^= rax;              //xor r8, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53B82F]
            r8 ^= rax;              //xor r8, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53B8F5]
            rax += 0x673BCC74;              //add rax, 0x673BCC74
            rax += rbx;             //add rax, rbx
            r8 ^= rax;              //xor r8, rax
            rax = 0x14CEC15D15237845;               //mov rax, 0x14CEC15D15237845
            r8 *= rax;              //imul r8, rax
            rax = 0xC6C8F26557A42C57;               //mov rax, 0xC6C8F26557A42C57
            r8 *= rax;              //imul r8, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            return r8;
        }
        case 2:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);              //mov r9, [0x000000000890E54F]
            rax = r8;               //mov rax, r8
            rax >>= 0xC;            //shr rax, 0x0C
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x18;           //shr rax, 0x18
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x30;           //shr rax, 0x30
            r8 ^= rax;              //xor r8, rax
            r8 -= rbx;              //sub r8, rbx
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = baseAddr + 0x40BA9587;                 //lea rax, [0x000000003E0E4B21]
            r8 += rbx;              //add r8, rbx
            r8 += rax;              //add r8, rax
            rax = 0xB820512AEEAE20F1;               //mov rax, 0xB820512AEEAE20F1
            r8 *= rax;              //imul r8, rax
            rax = 0x5B4702F448FEE148;               //mov rax, 0x5B4702F448FEE148
            r8 ^= rax;              //xor r8, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53B572]
            r8 += rax;              //add r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x12;           //shr rax, 0x12
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x24;           //shr rax, 0x24
            r8 ^= rax;              //xor r8, rax
            return r8;
        }
        case 3:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890E01D]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53AEEA]
            r8 -= rax;              //sub r8, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53AD6C]
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x13;           //shr rax, 0x13
            r8 ^= rax;              //xor r8, rax
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rax = r8;               //mov rax, r8
            rcx ^= r10;             //xor rcx, r10
            rax >>= 0x26;           //shr rax, 0x26
            rcx = ~rcx;             //not rcx
            r8 ^= rax;              //xor r8, rax
            r8 *= driver::read<uint64_t>(rcx + 0x7);           //imul r8, [rcx+0x07]
            rax = rbx;              //mov rax, rbx
            rax = ~rax;             //not rax
            uintptr_t RSP_0xFFFFFFFFFFFFFFC8;
            RSP_0xFFFFFFFFFFFFFFC8 = baseAddr + 0x639AA956;              //lea rax, [0x0000000060EE5ACB] : RBP+0xFFFFFFFFFFFFFFC8
            rax += RSP_0xFFFFFFFFFFFFFFC8;          //add rax, [rbp-0x38]
            r8 ^= rax;              //xor r8, rax
            rax = 0xEF7AA6541B0960DD;               //mov rax, 0xEF7AA6541B0960DD
            r8 ^= rax;              //xor r8, rax
            rax = 0xAC44478E4E7E319F;               //mov rax, 0xAC44478E4E7E319F
            r8 *= rax;              //imul r8, rax
            rax = 0x69DF0E377EDBC9BB;               //mov rax, 0x69DF0E377EDBC9BB
            r8 ^= rax;              //xor r8, rax
            return r8;
        }
        case 4:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);              //mov r9, [0x000000000890DBB2]
            rax = 0x6B6B6FEB24A18CBC;               //mov rax, 0x6B6B6FEB24A18CBC
            r8 ^= rax;              //xor r8, rax
            rax = 0xE26425F12DE4CEB;                //mov rax, 0xE26425F12DE4CEB
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x15;           //shr rax, 0x15
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x2A;           //shr rax, 0x2A
            r8 ^= rax;              //xor r8, rax
            r8 += rbx;              //add r8, rbx
            rax = 0xC6BD746DB1DF1B31;               //mov rax, 0xC6BD746DB1DF1B31
            r8 *= rax;              //imul r8, rax
            r8 -= baseAddr;              //sub r8, [rbp-0x08] -- didn't find trace -> use base
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = r8;               //mov rax, r8
            rax >>= 0x1;            //shr rax, 0x01
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x2;            //shr rax, 0x02
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x4;            //shr rax, 0x04
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x8;            //shr rax, 0x08
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x10;           //shr rax, 0x10
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x20;           //shr rax, 0x20
            r8 ^= rax;              //xor r8, rax
            return r8;
        }
        case 5:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890D4CA]
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rax = rbx * 0xFFFFFFFFFFFFFFFE;                 //imul rax, rbx, 0xFFFFFFFFFFFFFFFE
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            r8 += rax;              //add r8, rax
            rcx ^= r10;             //xor rcx, r10
            rax = baseAddr + 0x5F737FAA;                 //lea rax, [0x000000005CC7239B]
            rcx = ~rcx;             //not rcx
            r8 += rax;              //add r8, rax
            r8 *= driver::read<uint64_t>(rcx + 0x7);           //imul r8, [rcx+0x07]
            rax = r8;               //mov rax, r8
            rax >>= 0x19;           //shr rax, 0x19
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x32;           //shr rax, 0x32
            r8 ^= rax;              //xor r8, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53A27F]
            rax += 0x6987CC3C;              //add rax, 0x6987CC3C
            rax += rbx;             //add rax, rbx
            r8 += rax;              //add r8, rax
            rax = 0xBEC2B746A9461603;               //mov rax, 0xBEC2B746A9461603
            r8 *= rax;              //imul r8, rax
            rax = 0x7D25D991052F24B5;               //mov rax, 0x7D25D991052F24B5
            r8 += rax;              //add r8, rax
            rax = 0x6B9AD86F193C7172;               //mov rax, 0x6B9AD86F193C7172
            r8 += rax;              //add r8, rax
            return r8;
        }
        case 6:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890D073]
            r13 = baseAddr + 0x50AF1F4F;                 //lea r13, [0x000000004E02C15A]
            r8 += rbx;              //add r8, rbx
            rax = rbx;              //mov rax, rbx
            rax ^= r13;             //xor rax, r13
            r8 -= rax;              //sub r8, rax
            rax = 0xFA37AFACEF63040B;               //mov rax, 0xFA37AFACEF63040B
            r8 ^= rax;              //xor r8, rax
            rax = 0xE15A50F0F0B4D5D9;               //mov rax, 0xE15A50F0F0B4D5D9
            r8 *= rax;              //imul r8, rax
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rax = baseAddr + 0xEE8B;             //lea rax, [0xFFFFFFFFFD548C98]
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rax -= rbx;             //sub rax, rbx
            r8 ^= rax;              //xor r8, rax
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            r8 *= driver::read<uint64_t>(rcx + 0x7);           //imul r8, [rcx+0x07]
            rax = 0x61E687AD8B6807D4;               //mov rax, 0x61E687AD8B6807D4
            r8 += rax;              //add r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x15;           //shr rax, 0x15
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x2A;           //shr rax, 0x2A
            r8 ^= rax;              //xor r8, rax
            return r8;
        }
        case 7:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890CB6E]
            r14 = baseAddr + 0xBEE4;             //lea r14, [0xFFFFFFFFFD545BE5]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5399AF]
            r8 ^= rax;              //xor r8, rax
            rax = 0x8DB3E6B3BD449D8;                //mov rax, 0x8DB3E6B3BD449D8
            r8 += rax;              //add r8, rax
            rax = 0x7CFD8CC5318E532F;               //mov rax, 0x7CFD8CC5318E532F
            r8 *= rax;              //imul r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x7;            //shr rax, 0x07
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0xE;            //shr rax, 0x0E
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x1C;           //shr rax, 0x1C
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x38;           //shr rax, 0x38
            r8 ^= rax;              //xor r8, rax
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rax = 0x6DE6E637B4DB68F1;               //mov rax, 0x6DE6E637B4DB68F1
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            r8 *= driver::read<uint64_t>(rcx + 0x7);           //imul r8, [rcx+0x07]
            r8 *= rax;              //imul r8, rax
            rax = rbx;              //mov rax, rbx
            rax -= r14;             //sub rax, r14
            r8 ^= rax;              //xor r8, rax
            r8 -= rbx;              //sub r8, rbx
            return r8;
        }
        case 8:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);              //mov r9, [0x000000000890C736]
            rax = r8;               //mov rax, r8
            rax >>= 0x1E;           //shr rax, 0x1E
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x3C;           //shr rax, 0x3C
            r8 ^= rax;              //xor r8, rax
            rax = 0xD16E8EE163C9A6B;                //mov rax, 0xD16E8EE163C9A6B
            r8 *= rax;              //imul r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0xE;            //shr rax, 0x0E
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x1C;           //shr rax, 0x1C
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x38;           //shr rax, 0x38
            r8 ^= rax;              //xor r8, rax
            rax = 0xA9C58221B90E7C46;               //mov rax, 0xA9C58221B90E7C46
            r8 ^= rax;              //xor r8, rax
            rax = 0x55F6ED3AB42B87A0;               //mov rax, 0x55F6ED3AB42B87A0
            r8 -= rax;              //sub r8, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53941F]
            r8 += rax;              //add r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x14;           //shr rax, 0x14
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x28;           //shr rax, 0x28
            r8 ^= rax;              //xor r8, rax
            return r8;
        }
        case 9:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890C09D]
            r13 = baseAddr + 0x6EC75C18;                 //lea r13, [0x000000006C1AEE4D]
            rcx = rbx;              //mov rcx, rbx
            rax = baseAddr + 0xFCE2;             //lea rax, [0xFFFFFFFFFD548D77]
            rcx *= rax;             //imul rcx, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53908A]
            rcx -= rax;             //sub rcx, rax
            rax = rbx;              //mov rax, rbx
            r8 += rcx;              //add r8, rcx
            rax = ~rax;             //not rax
            r8 ^= rax;              //xor r8, rax
            r8 ^= r13;              //xor r8, r13
            rax = r8;               //mov rax, r8
            rax >>= 0x7;            //shr rax, 0x07
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0xE;            //shr rax, 0x0E
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x1C;           //shr rax, 0x1C
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x38;           //shr rax, 0x38
            r8 ^= rax;              //xor r8, rax
            r14 = 0xB691FFD9C9D61B2E;               //mov r14, 0xB691FFD9C9D61B2E
            r8 += r14;              //add r8, r14
            r14 = 0x89C1B16D1EAC4B85;               //mov r14, 0x89C1B16D1EAC4B85
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            r8 ^= r14;              //xor r8, r14
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = 0x272542A0099256AB;               //mov rax, 0x272542A0099256AB
            r8 *= rax;              //imul r8, rax
            return r8;
        }
        case 10:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890BB88]
            r13 = baseAddr + 0x24E689C1;                 //lea r13, [0x00000000223A16E1]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD538BC4]
            rax += 0x240D8AB0;              //add rax, 0x240D8AB0
            rax += rbx;             //add rax, rbx
            r8 ^= rax;              //xor r8, rax
            rcx = rbx;              //mov rcx, rbx
            rax = baseAddr + 0x3B21;             //lea rax, [0xFFFFFFFFFD53C48A]
            rcx *= rax;             //imul rcx, rax
            rax = rbx;              //mov rax, rbx
            rax = ~rax;             //not rax
            r8 += rcx;              //add r8, rcx
            rax += r13;             //add rax, r13
            r8 ^= rax;              //xor r8, rax
            rax = 0x489A1BC87CDCD670;               //mov rax, 0x489A1BC87CDCD670
            r8 ^= rax;              //xor r8, rax
            rax = 0xA00242052F60AE53;               //mov rax, 0xA00242052F60AE53
            r8 ^= rax;              //xor r8, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = 0xBDB64B81FECB6E7D;               //mov rax, 0xBDB64B81FECB6E7D
            r8 *= rax;              //imul r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x28;           //shr rax, 0x28
            r8 ^= rax;              //xor r8, rax
            return r8;
        }
        case 11:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890B6B1]
            rax = r8;               //mov rax, r8
            rax >>= 0x15;           //shr rax, 0x15
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x2A;           //shr rax, 0x2A
            r8 ^= rax;              //xor r8, rax
            rax = 0xD3A53D9499733245;               //mov rax, 0xD3A53D9499733245
            r8 *= rax;              //imul r8, rax
            rax = 0x72C2AC821062ABD1;               //mov rax, 0x72C2AC821062ABD1
            r8 ^= rax;              //xor r8, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53835D]
            r8 -= rax;              //sub r8, rax
            r8 += 0xFFFFFFFFFFFF4954;               //add r8, 0xFFFFFFFFFFFF4954
            r8 += rbx;              //add r8, rbx
            rax = r8;               //mov rax, r8
            rax >>= 0x1;            //shr rax, 0x01
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x2;            //shr rax, 0x02
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x4;            //shr rax, 0x04
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x8;            //shr rax, 0x08
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x10;           //shr rax, 0x10
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x20;           //shr rax, 0x20
            r8 ^= rax;              //xor r8, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5386EB]
            r8 ^= rax;              //xor r8, rax
            rax = rbx;              //mov rax, rbx
            uintptr_t RSP_0xFFFFFFFFFFFFFF80;
            RSP_0xFFFFFFFFFFFFFF80 = baseAddr + 0x5B0222F4;              //lea rax, [0x000000005855AAF5] : RBP+0xFFFFFFFFFFFFFF80
            rax *= RSP_0xFFFFFFFFFFFFFF80;          //imul rax, [rbp-0x80]
            r8 += rax;              //add r8, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            return r8;
        }
        case 12:
        {
            r11 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r11, [0x000000000890B14C]
            r13 = baseAddr + 0x852;              //lea r13, [0xFFFFFFFFFD538B36]
            rax = 0xF7D4FABCE6FC022;                //mov rax, 0xF7D4FABCE6FC022
            r8 += rax;              //add r8, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r11;             //xor rax, r11
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53809E]
            r8 ^= rax;              //xor r8, rax
            r8 -= rax;              //sub r8, rax
            rax = 0x5C9D9DBA026E85B7;               //mov rax, 0x5C9D9DBA026E85B7
            r8 *= rax;              //imul r8, rax
            rax = r8;               //mov rax, r8
            rcx = rbx;              //mov rcx, rbx
            rax >>= 0x21;           //shr rax, 0x21
            rcx = ~rcx;             //not rcx
            rcx *= r13;             //imul rcx, r13
            rcx ^= rax;             //xor rcx, rax
            r8 ^= rcx;              //xor r8, rcx
            r8 += rbx;              //add r8, rbx
            return r8;
        }
        case 13:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890AD91]
            r14 = baseAddr + 0x12585A59;                 //lea r14, [0x000000000FABD982]
            rax = rbx;              //mov rax, rbx
            rax = ~rax;             //not rax
            rax ^= r14;             //xor rax, r14
            r8 += rax;              //add r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x8;            //shr rax, 0x08
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x10;           //shr rax, 0x10
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x20;           //shr rax, 0x20
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x11;           //shr rax, 0x11
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x22;           //shr rax, 0x22
            r8 ^= rax;              //xor r8, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = 0xA4979265BBC7E3D5;               //mov rax, 0xA4979265BBC7E3D5
            r8 *= rax;              //imul r8, rax
            rax = rbx;              //mov rax, rbx
            rax = ~rax;             //not rax
            rax -= baseAddr;             //sub rax, [rbp-0x08] -- didn't find trace -> use base
            rax -= 0x756FAD6E;              //sub rax, 0x756FAD6E
            r8 ^= rax;              //xor r8, rax
            rax = baseAddr + 0x78217335;                 //lea rax, [0x000000007574F077]
            r8 += rbx;              //add r8, rbx
            r8 += rax;              //add r8, rax
            rax = 0xC20F4E2AD24BC517;               //mov rax, 0xC20F4E2AD24BC517
            r8 ^= rax;              //xor r8, rax
            return r8;
        }
        case 14:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);              //mov r9, [0x000000000890A828]
            rax = r8;               //mov rax, r8
            rax >>= 0x16;           //shr rax, 0x16
            r8 ^= rax;              //xor r8, rax
            rax = r8;               //mov rax, r8
            rax >>= 0x2C;           //shr rax, 0x2C
            r8 ^= rax;              //xor r8, rax
            rax = 0xAF96B7C88EDF2B75;               //mov rax, 0xAF96B7C88EDF2B75
            r8 *= rax;              //imul r8, rax
            r8 ^= rbx;              //xor r8, rbx
            r8 += rbx;              //add r8, rbx
            uintptr_t RSP_0xFFFFFFFFFFFFFFC0;
            RSP_0xFFFFFFFFFFFFFFC0 = baseAddr + 0x3CF1;          //lea rax, [0xFFFFFFFFFD53B621] : RBP+0xFFFFFFFFFFFFFFC0
            r8 += RSP_0xFFFFFFFFFFFFFFC0;           //add r8, [rbp-0x40]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = 0x7B695E53D3CD7B7F;               //mov rax, 0x7B695E53D3CD7B7F
            r8 *= rax;              //imul r8, rax
            rax = 0x56A40B352BF2FDB7;               //mov rax, 0x56A40B352BF2FDB7
            r8 -= rax;              //sub r8, rax
            rax = baseAddr + 0x32FFEB8B;                 //lea rax, [0x0000000030536448]
            rax = ~rax;             //not rax
            rax *= rbx;             //imul rax, rbx
            r8 += rax;              //add r8, rax
            return r8;
        }
        case 15:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB3D2E55);             //mov r10, [0x000000000890A2D2]
            r13 = baseAddr + 0x23AC2B6F;                 //lea r13, [0x0000000020FF9FD9]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD53724D]
            r8 -= rax;              //sub r8, rax
            r8 += rbx;              //add r8, rbx
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = ~rax;             //not rax
            r8 *= driver::read<uint64_t>(rax + 0x7);           //imul r8, [rax+0x07]
            rax = r8;               //mov rax, r8
            rax >>= 0x17;           //shr rax, 0x17
            r8 ^= rax;              //xor r8, rax
            rcx = r8;               //mov rcx, r8
            rcx >>= 0x2E;           //shr rcx, 0x2E
            r8 ^= rcx;              //xor r8, rcx
            rax = r13;              //mov rax, r13
            rax = ~rax;             //not rax
            rax ^= rbx;             //xor rax, rbx
            r8 -= rax;              //sub r8, rax
            rax = 0xAE9091426078C4DF;               //mov rax, 0xAE9091426078C4DF
            r8 *= rax;              //imul r8, rax
            rax = 0x2E839B5F3DB76D2B;               //mov rax, 0x2E839B5F3DB76D2B
            r8 += rax;              //add r8, rax
            rax = 0x632E9341FBDD9A7C;               //mov rax, 0x632E9341FBDD9A7C
            r8 -= rax;              //sub r8, rax
            return r8;
        }
        }
    };

    uint64_t steam_decrypt_bone_base(uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rdx = driver::read<uint64_t>(baseAddr + 0x11946DE8);
        if (!rdx)
            return rdx;
        r9 = peb;                //mov r9, gs:[rax]
        rax = r9;               //mov rax, r9
        rax <<= 0x22;           //shl rax, 0x22
        rax = _byteswap_uint64(rax);            //bswap rax
        rax &= 0xF;
        switch (rax) {
        case 0:
        {
            rbx = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov rbx, [0x000000000899332F]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= rbx;             //xor rax, rbx
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5C014B]
            rdx -= rax;             //sub rdx, rax
            rax = 0xC98EF2FFB1E013D2;               //mov rax, 0xC98EF2FFB1E013D2
            rdx += 0xFFFFFFFFFFFFC795;              //add rdx, 0xFFFFFFFFFFFFC795
            rdx += r9;              //add rdx, r9
            rdx ^= rax;             //xor rdx, rax
            rdx ^= r9;              //xor rdx, r9
            rax = 0x1AE0F1058D3590F1;               //mov rax, 0x1AE0F1058D3590F1
            rdx *= rax;             //imul rdx, rax
            rax = 0x1EAC0325CBA779BC;               //mov rax, 0x1EAC0325CBA779BC
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1F;           //shr rax, 0x1F
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x3E;           //shr rax, 0x3E
            rdx ^= rax;             //xor rdx, rax
            rdx ^= r9;              //xor rdx, r9
            return rdx;
        }
        case 1:
        {
            r15 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov r15, [0x0000000008992E77]
            r14 = baseAddr + 0x437D3D7F;                 //lea r14, [0x0000000040D93CBA]
            rax = 0x311E3C7DD1297B69;               //mov rax, 0x311E3C7DD1297B69
            rdx *= rax;             //imul rdx, rax
            rcx = r9;               //mov rcx, r9
            rcx = ~rcx;             //not rcx
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r15;             //xor rax, r15
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rax = r14;              //mov rax, r14
            rax = ~rax;             //not rax
            rcx += rax;             //add rcx, rax
            rdx ^= rcx;             //xor rdx, rcx
            rax = rdx;              //mov rax, rdx
            rax >>= 0x28;           //shr rax, 0x28
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x13;           //shr rax, 0x13
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x26;           //shr rax, 0x26
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BFD68]
            rax += 0x3B261317;              //add rax, 0x3B261317
            rax += r9;              //add rax, r9
            rdx += rax;             //add rdx, rax
            rax = 0x85B82AEE944DCF96;               //mov rax, 0x85B82AEE944DCF96
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BFE5B]
            rdx += rax;             //add rdx, rax
            return rdx;
        }
        case 2:
        {
            rbx = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov rbx, [0x00000000089929D2]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x25;           //shr rax, 0x25
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0xC;            //shr rax, 0x0C
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x18;           //shr rax, 0x18
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x30;           //shr rax, 0x30
            rdx ^= rax;             //xor rdx, rax
            rdx += r9;              //add rdx, r9
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= rbx;             //xor rax, rbx
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rdx ^= r9;              //xor rdx, r9
            rax = 0x6B65DF2C3A88AE69;               //mov rax, 0x6B65DF2C3A88AE69
            rdx -= rax;             //sub rdx, rax
            rax = 0xA4B331303E4E7A67;               //mov rax, 0xA4B331303E4E7A67
            rdx *= rax;             //imul rdx, rax
            rax = 0x6A137DDDFCE4C0D7;               //mov rax, 0x6A137DDDFCE4C0D7
            rdx -= rax;             //sub rdx, rax
            return rdx;
        }
        case 3:
        {
            r8 = baseAddr + 0x1314A155;          //lea r8, [0x00000000107097C3]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            uintptr_t RSP_0x38;
            RSP_0x38 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);                //mov rax, [0x0000000008992590] : RSP+0x38
            rax ^= RSP_0x38;                //xor rax, [rsp+0x38]
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BF570]
            rdx -= rax;             //sub rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1F;           //shr rax, 0x1F
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x3E;           //shr rax, 0x3E
            rdx ^= rax;             //xor rdx, rax
            rdx ^= r9;              //xor rdx, r9
            rax = r8;               //mov rax, r8
            rax -= r9;              //sub rax, r9
            rdx ^= rax;             //xor rdx, rax
            rax = 0xD5A4D08183955257;               //mov rax, 0xD5A4D08183955257
            rdx *= rax;             //imul rdx, rax
            rax = 0x8DC8AE43913090FA;               //mov rax, 0x8DC8AE43913090FA
            rdx ^= rax;             //xor rdx, rax
            return rdx;
        }
        case 4:
        {
            rsi = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov rsi, [0x00000000089922A8]
            rax = 0xF7A45523CB2EF07F;               //mov rax, 0xF7A45523CB2EF07F
            rdx ^= rax;             //xor rdx, rax
            rdx -= r9;              //sub rdx, r9
            rdx -= r9;              //sub rdx, r9
            rdx -= r9;              //sub rdx, r9
            rax = rdx;              //mov rax, rdx
            rax >>= 0x14;           //shr rax, 0x14
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x28;           //shr rax, 0x28
            rdx ^= rax;             //xor rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= rsi;             //xor rax, rsi
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BEFE5]
            rax += 0x8F29;          //add rax, 0x8F29
            rax += r9;              //add rax, r9
            rdx ^= rax;             //xor rdx, rax
            rax = 0xD43375ADC5407E51;               //mov rax, 0xD43375ADC5407E51
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 5:
        {
            rbx = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov rbx, [0x0000000008991E25]
            r11 = baseAddr + 0x12426297;                 //lea r11, [0x000000000F9E5174]
            rax = 0x7C5DF0A12057BE6;                //mov rax, 0x7C5DF0A12057BE6
            rdx -= rax;             //sub rdx, rax
            rax = 0x83F8FC0408B5D1AB;               //mov rax, 0x83F8FC0408B5D1AB
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr + 0x158DE932;                 //lea rax, [0x0000000012E9D68B]
            rax = ~rax;             //not rax
            rax *= r9;              //imul rax, r9
            rdx += rax;             //add rdx, rax
            rax = r9;               //mov rax, r9
            rax *= r11;             //imul rax, r11
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BECAC]
            rax += 0x5541;          //add rax, 0x5541
            rax += r9;              //add rax, r9
            rdx += rax;             //add rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x5;            //shr rax, 0x05
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0xA;            //shr rax, 0x0A
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x14;           //shr rax, 0x14
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x28;           //shr rax, 0x28
            rdx ^= rax;             //xor rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= rbx;             //xor rax, rbx
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rax = 0x3F31D045C89ED8C5;               //mov rax, 0x3F31D045C89ED8C5
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 6:
        {
            r11 = baseAddr + 0x6DA9DAD4;                 //lea r11, [0x000000006B05C459]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x6;            //shr rax, 0x06
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0xC;            //shr rax, 0x0C
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x18;           //shr rax, 0x18
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x30;           //shr rax, 0x30
            rdx ^= rax;             //xor rdx, rax
            rax = 0x7564570D161CA18D;               //mov rax, 0x7564570D161CA18D
            rdx *= rax;             //imul rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x26;           //shr rax, 0x26
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BE724]
            rax += 0x144205B7;              //add rax, 0x144205B7
            rax += r9;              //add rax, r9
            rdx ^= rax;             //xor rdx, rax
            rax = 0x80C6B6FC948F6729;               //mov rax, 0x80C6B6FC948F6729
            rdx *= rax;             //imul rdx, rax
            rax = 0x31DF20582505A415;               //mov rax, 0x31DF20582505A415
            rdx += rax;             //add rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            uintptr_t RSP_0x38;
            RSP_0x38 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);                //mov rax, [0x0000000008991884] : RSP+0x38
            rax ^= RSP_0x38;                //xor rax, [rsp+0x38]
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rdx += r11;             //add rdx, r11
            rcx = r9;               //mov rcx, r9
            rcx = ~rcx;             //not rcx
            rdx += rcx;             //add rdx, rcx
            return rdx;
        }
        case 7:
        {
            rsi = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov rsi, [0x00000000089914D9]
            rbx = baseAddr + 0x4354;             //lea rbx, [0xFFFFFFFFFD5C28F1]
            rdx ^= r9;              //xor rdx, r9
            rax = rdx;              //mov rax, rdx
            rax >>= 0xD;            //shr rax, 0x0D
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1A;           //shr rax, 0x1A
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x34;           //shr rax, 0x34
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x7;            //shr rax, 0x07
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0xE;            //shr rax, 0x0E
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1C;           //shr rax, 0x1C
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x38;           //shr rax, 0x38
            rdx ^= rax;             //xor rdx, rax
            rax = 0xCCB3012D7BB7524F;               //mov rax, 0xCCB3012D7BB7524F
            rdx *= rax;             //imul rdx, rax
            rax = 0x11516F5E5F563F90;               //mov rax, 0x11516F5E5F563F90
            rdx -= rax;             //sub rdx, rax
            rax = r9;               //mov rax, r9
            rax = ~rax;             //not rax
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rax *= rbx;             //imul rax, rbx
            rcx ^= rsi;             //xor rcx, rsi
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx += rax;             //add rdx, rax
            rdx *= driver::read<uint64_t>(rcx + 0x11);                 //imul rdx, [rcx+0x11]
            return rdx;
        }
        case 8:
        {
            r11 = baseAddr + 0x7D814959;                 //lea r11, [0x000000007ADD2A82]
            rdx -= r9;              //sub rdx, r9
            rax = 0xEDC13D6B57B6E285;               //mov rax, 0xEDC13D6B57B6E285
            rdx *= rax;             //imul rdx, rax
            rax = r9;               //mov rax, r9
            rax ^= r11;             //xor rax, r11
            rax += r9;              //add rax, r9
            rdx += rax;             //add rdx, rax
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            uintptr_t RSP_0x38;
            RSP_0x38 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);                //mov rax, [0x0000000008991065] : RSP+0x38
            rcx ^= RSP_0x38;                //xor rcx, [rsp+0x38]
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx *= driver::read<uint64_t>(rcx + 0x11);                 //imul rdx, [rcx+0x11]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x21;           //shr rax, 0x21
            rdx ^= rax;             //xor rdx, rax
            rdx += r9;              //add rdx, r9
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BDFB2]
            rdx ^= rax;             //xor rdx, rax
            return rdx;
        }
        case 9:
        {
            r11 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov r11, [0x0000000008990D2A]
            rax = rdx;              //mov rax, rdx
            rax >>= 0xB;            //shr rax, 0x0B
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x16;           //shr rax, 0x16
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x2C;           //shr rax, 0x2C
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BD9E0]
            rdx ^= rax;             //xor rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r11;             //xor rax, r11
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rax = rdx;              //mov rax, rdx
            rax >>= 0xB;            //shr rax, 0x0B
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x16;           //shr rax, 0x16
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x2C;           //shr rax, 0x2C
            rdx ^= rax;             //xor rdx, rax
            rax = 0x53198E81F809E193;               //mov rax, 0x53198E81F809E193
            rax -= r9;              //sub rax, r9
            rax -= baseAddr;             //sub rax, [rbp-0x48] -- didn't find trace -> use base
            rdx += rax;             //add rdx, rax
            rax = 0x5E76F88978AFE528;               //mov rax, 0x5E76F88978AFE528
            rdx += rax;             //add rdx, rax
            rax = 0x33557C5CEFBE234B;               //mov rax, 0x33557C5CEFBE234B
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 10:
        {
            r14 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov r14, [0x0000000008990839]
            rsi = baseAddr + 0x9688;             //lea rsi, [0xFFFFFFFFFD5C6F85]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BD7A8]
            rdx -= rax;             //sub rdx, rax
            rcx = rdx;              //mov rcx, rdx
            rcx >>= 0x27;           //shr rcx, 0x27
            rcx ^= rdx;             //xor rcx, rdx
            rdx = r9;               //mov rdx, r9
            rdx *= rsi;             //imul rdx, rsi
            rdx += rcx;             //add rdx, rcx
            rax = rdx;              //mov rax, rdx
            rax >>= 0x13;           //shr rax, 0x13
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x26;           //shr rax, 0x26
            rdx ^= rax;             //xor rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r14;             //xor rax, r14
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rax = 0x3331EF2FFF7DD801;               //mov rax, 0x3331EF2FFF7DD801
            rdx *= rax;             //imul rdx, rax
            rax = 0x2130706D6228E017;               //mov rax, 0x2130706D6228E017
            rdx ^= rax;             //xor rdx, rax
            return rdx;
        }
        case 11:
        {
            rsi = baseAddr + 0x7C2A0085;                 //lea rsi, [0x000000007985D4CD]
            r14 = baseAddr + 0x1E13DCA3;                 //lea r14, [0x000000001B6FB0DA]
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rax = r14;              //mov rax, r14
            rax = ~rax;             //not rax
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            uintptr_t RSP_0x38;
            RSP_0x38 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);                //mov rax, [0x0000000008990384] : RSP+0x38
            rcx ^= RSP_0x38;                //xor rcx, [rsp+0x38]
            rax += r9;              //add rax, r9
            rdx += rax;             //add rdx, rax
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx *= driver::read<uint64_t>(rcx + 0x11);                 //imul rdx, [rcx+0x11]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BD085]
            rax += 0x9D9E;          //add rax, 0x9D9E
            rax += r9;              //add rax, r9
            rdx += rax;             //add rdx, rax
            rax = r9;               //mov rax, r9
            rax -= baseAddr;             //sub rax, [rbp-0x48] -- didn't find trace -> use base
            rdx += rax;             //add rdx, rax
            rax = 0x10CE41F37EB30D3D;               //mov rax, 0x10CE41F37EB30D3D
            rdx *= rax;             //imul rdx, rax
            rax = 0x3078E9571E8D51B0;               //mov rax, 0x3078E9571E8D51B0
            rdx -= rax;             //sub rdx, rax
            rax = 0x13796DAAB7614CCB;               //mov rax, 0x13796DAAB7614CCB
            rdx += rax;             //add rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x11;           //shr rax, 0x11
            rdx ^= rax;             //xor rdx, rax
            rcx = rsi;              //mov rcx, rsi
            rcx = ~rcx;             //not rcx
            rcx *= r9;              //imul rcx, r9
            rax = rdx;              //mov rax, rdx
            rax >>= 0x22;           //shr rax, 0x22
            rcx ^= rax;             //xor rcx, rax
            rdx ^= rcx;             //xor rdx, rcx
            return rdx;
        }
        case 12:
        {
            r11 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov r11, [0x000000000898FF4E]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r11;             //xor rax, r11
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rdx -= r9;              //sub rdx, r9
            rax = 0x509EB372CDB3AEF3;               //mov rax, 0x509EB372CDB3AEF3
            rdx *= rax;             //imul rdx, rax
            rax = 0x3978478545AD0B0E;               //mov rax, 0x3978478545AD0B0E
            rdx += rax;             //add rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x11;           //shr rax, 0x11
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x22;           //shr rax, 0x22
            rdx ^= rax;             //xor rdx, rax
            rax = 0xF1F3C3AA4D6D1089;               //mov rax, 0xF1F3C3AA4D6D1089
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 13:
        {
            r14 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov r14, [0x000000000898FAD8]
            rsi = baseAddr + 0x7FFA;             //lea rsi, [0xFFFFFFFFFD5C4B96]
            rax = rdx;              //mov rax, rdx
            rax >>= 0xE;            //shr rax, 0x0E
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1C;           //shr rax, 0x1C
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rax >>= 0x38;           //shr rax, 0x38
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rdx ^= rax;             //xor rdx, rax
            rcx ^= r14;             //xor rcx, r14
            rdx += r9;              //add rdx, r9
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx *= driver::read<uint64_t>(rcx + 0x11);                 //imul rdx, [rcx+0x11]
            rax = 0xEA5C4AF83EEC98D;                //mov rax, 0xEA5C4AF83EEC98D
            rdx += rax;             //add rdx, rax
            rax = rsi;              //mov rax, rsi
            rax = ~rax;             //not rax
            rax ^= r9;              //xor rax, r9
            rdx ^= rax;             //xor rdx, rax
            rax = 0x58CCD785809FBA65;               //mov rax, 0x58CCD785809FBA65
            rdx *= rax;             //imul rdx, rax
            rax = 0xCB1252FFDD097729;               //mov rax, 0xCB1252FFDD097729
            rdx *= rax;             //imul rdx, rax
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BC795]
            rax += 0x1CFB;          //add rax, 0x1CFB
            rax += r9;              //add rax, r9
            rdx += rax;             //add rdx, rax
            return rdx;
        }
        case 14:
        {
            rsi = driver::read<uint64_t>(baseAddr + 0xB3D2F29);             //mov rsi, [0x000000000898F55B]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1C;           //shr rax, 0x1C
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x38;           //shr rax, 0x38
            rax ^= rdx;             //xor rax, rdx
            rdx = baseAddr;              //lea rdx, [0xFFFFFFFFFD5BC2EE]
            rax -= rdx;             //sub rax, rdx
            rdx = r9 + 0xffffffffd3bc8867;          //lea rdx, [r9-0x2C437799]
            rdx += rax;             //add rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= rsi;             //xor rax, rsi
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);                 //imul rdx, [rax+0x11]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BC200]
            rdx -= rax;             //sub rdx, rax
            rax = 0x311461FA31B150C8;               //mov rax, 0x311461FA31B150C8
            rdx ^= rax;             //xor rdx, rax
            rax = 0x3D057F65AC2E944D;               //mov rax, 0x3D057F65AC2E944D
            rdx += rax;             //add rdx, rax
            rax = 0x3EA61F392134306F;               //mov rax, 0x3EA61F392134306F
            rdx *= rax;             //imul rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x16;           //shr rax, 0x16
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x2C;           //shr rax, 0x2C
            rdx ^= rax;             //xor rdx, rax
            return rdx;
        }
        case 15:
        {
            rax = rdx;              //mov rax, rdx
            rax >>= 0x25;           //shr rax, 0x25
            rdx ^= rax;             //xor rdx, rax
            rdx -= r9;              //sub rdx, r9
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            uintptr_t RSP_0x38;
            RSP_0x38 = driver::read<uint64_t>(baseAddr + 0xB3D2F29);                //mov rax, [0x000000000898F0F3] : RSP+0x38
            rcx ^= RSP_0x38;                //xor rcx, [rsp+0x38]
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BBF91]
            rax += 0x953;           //add rax, 0x953
            rax += r9;              //add rax, r9
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx ^= rax;             //xor rdx, rax
            rdx *= driver::read<uint64_t>(rcx + 0x11);                 //imul rdx, [rcx+0x11]
            rax = 0xEDC186E4F45D82CF;               //mov rax, 0xEDC186E4F45D82CF
            rdx *= rax;             //imul rdx, rax
            rdx -= r9;              //sub rdx, r9
            rax = baseAddr;              //lea rax, [0xFFFFFFFFFD5BBE81]
            rdx -= rax;             //sub rdx, rax
            rax = 0x579691DADE4159FD;               //mov rax, 0x579691DADE4159FD
            rdx *= rax;             //imul rdx, rax
            rax = 0x20B206512FA8AEE;                //mov rax, 0x20B206512FA8AEE
            rdx -= rax;             //sub rdx, rax
            rax = 0x804CFF40F9D9BEBF;               //mov rax, 0x804CFF40F9D9BEBF
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        }
    }

    uint64_t steam_get_bone_index(uint32_t bone_index, uint64_t baseAddr)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rbx = bone_index;
        rcx = rbx * 0x13C8;
        rax = 0xD8CE01BF28E39A45;               //mov rax, 0xD8CE01BF28E39A45
        rbx = baseAddr;              //lea rbx, [0xFFFFFFFFFD529F8E]
        rax = _umul128(rax, rcx, (uintptr_t*)&rdx);             //mul rcx
        r10 = 0xB225E47EA96E19B5;               //mov r10, 0xB225E47EA96E19B5
        rdx >>= 0xD;            //shr rdx, 0x0D
        rax = rdx * 0x25C9;             //imul rax, rdx, 0x25C9
        rcx -= rax;             //sub rcx, rax
        rax = 0xCEA41D97BF6494DF;               //mov rax, 0xCEA41D97BF6494DF
        r8 = rcx * 0x25C9;              //imul r8, rcx, 0x25C9
        rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
        rax = r8;               //mov rax, r8
        rax -= rdx;             //sub rax, rdx
        rax >>= 0x1;            //shr rax, 0x01
        rax += rdx;             //add rax, rdx
        rax >>= 0xE;            //shr rax, 0x0E
        rax = rax * 0x46D4;             //imul rax, rax, 0x46D4
        r8 -= rax;              //sub r8, rax
        rax = 0x526226F064679F75;               //mov rax, 0x526226F064679F75
        rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
        rax = 0xD79435E50D79435F;               //mov rax, 0xD79435E50D79435F
        rdx >>= 0x9;            //shr rdx, 0x09
        rcx = rdx * 0x637;              //imul rcx, rdx, 0x637
        rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
        rdx >>= 0x4;            //shr rdx, 0x04
        rcx += rdx;             //add rcx, rdx
        rax = rcx * 0x26;               //imul rax, rcx, 0x26
        rcx = r8 + r8 * 4;              //lea rcx, [r8+r8*4]
        rcx <<= 0x3;            //shl rcx, 0x03
        rcx -= rax;             //sub rcx, rax
        rax = driver::read<uint16_t>(rcx + rbx * 1 + 0xA2FC460);            //movzx eax, word ptr [rcx+rbx*1+0xA2FC460]
        r8 = rax * 0x13C8;              //imul r8, rax, 0x13C8
        rax = r10;              //mov rax, r10
        rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
        rcx = r8;               //mov rcx, r8
        rax = r10;              //mov rax, r10
        rcx -= rdx;             //sub rcx, rdx
        rcx >>= 0x1;            //shr rcx, 0x01
        rcx += rdx;             //add rcx, rdx
        rcx >>= 0xD;            //shr rcx, 0x0D
        rcx = rcx * 0x25BD;             //imul rcx, rcx, 0x25BD
        r8 -= rcx;              //sub r8, rcx
        r9 = r8 * 0x319C;               //imul r9, r8, 0x319C
        rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
        rax = r9;               //mov rax, r9
        rax -= rdx;             //sub rax, rdx
        rax >>= 0x1;            //shr rax, 0x01
        rax += rdx;             //add rax, rdx
        rax >>= 0xD;            //shr rax, 0x0D
        rax = rax * 0x25BD;             //imul rax, rax, 0x25BD
        r9 -= rax;              //sub r9, rax
        rax = 0x842108421084211;                //mov rax, 0x842108421084211
        rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
        rax = r9;               //mov rax, r9
        rax -= rdx;             //sub rax, rdx
        rax >>= 0x1;            //shr rax, 0x01
        rax += rdx;             //add rax, rdx
        rax >>= 0xA;            //shr rax, 0x0A
        rcx = rax * 0x7C0;              //imul rcx, rax, 0x7C0
        rax = 0xE38E38E38E38E38F;               //mov rax, 0xE38E38E38E38E38F
        rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
        rdx >>= 0x3;            //shr rdx, 0x03
        rcx += rdx;             //add rcx, rdx
        rax = rcx + rcx * 8;            //lea rax, [rcx+rcx*8]
        rax += rax;             //add rax, rax
        rcx = r9 + r9 * 4;              //lea rcx, [r9+r9*4]
        rcx <<= 0x2;            //shl rcx, 0x02
        rcx -= rax;             //sub rcx, rax
        rsi = driver::read<uint16_t>(rcx + rbx * 1 + 0xA30B090);            //movsx esi, word ptr [rcx+rbx*1+0xA30B090]
        return rsi;
    }
}