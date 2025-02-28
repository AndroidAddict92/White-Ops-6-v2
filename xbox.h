namespace BO6 {
    static uint32_t refdef = 0xCB5E330;
    static uint32_t name_array = 0xCBA7318;
    static uint32_t name_array_pos = 0x1838;
    static uint32_t name_size = 0xC8;
    static uint32_t loot_ptr = 0xCB66CF0;
    static uint32_t loot_pos = 0x170;
    static uint32_t loot_valid = 0x124;
    static uint32_t loot_valid_supply = 0x126;
    static uint32_t loot_size = 0x1F0;
    static uint32_t camera_base = 0xC72B430;
    static uint32_t camera_pos = 0x204;
    static uint32_t local_index = 0xAB588;
    static uint32_t local_index_pos = 0x34C;
    static uint32_t recoil = 0x7360;
    static uint32_t game_mode = 0xB52D0C8;
    static uint32_t weapon_definitions = 0xC8F6B90;
    static uint32_t distribute = 0x103D2A48;
    static uint32_t visible_offset = 0xCFE50;
    static uint32_t visible = 0xCFE50;
    static uint32_t scoreboard = 0x64A40;
    static uint32_t scoreboard_size = 0x90;

    namespace bone {
        static uintptr_t base_pos = 0x1B4AE8;
        static uintptr_t index_struct_size = 0x1A0;
    }

    namespace player {
        static uint32_t size = 0x20C0;
        static uint32_t valid = 0x1EC8;
        static uint32_t pos = 0x1A70;
        static uint32_t team = 0x17B8;
        static uint32_t stance = 0xEF5;
        static uint32_t weapon_index = 0x1E28;
        static uint32_t dead_1 = 0x0;
        static uint32_t dead_2 = 0x0;
        static uint32_t local_entity = 0xCFE70;
        static uint32_t entity_size = 0x590;
        static uint32_t entity_type = 0x88;
        static uint32_t entity_valid = 0x1B8;
        static uint32_t entity_index = 0x80;
        static uint32_t entity_pos = entity_type + 0x1C;
    }
}

namespace BO6 {
    uint64_t gamepass_decrypt_client_info(uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rbx = driver::read<uint64_t>(baseAddr + 0xCB592D8);
        if (!rbx)
            return rbx;
        rcx = peb;              //mov rcx, gs:[rax]
        //failed to trace. base: 00007FF64F6C0000 It's possibly wrong   rdx = 0000000000000000
        rbx += 0xFFFFFFFFFFFF9357;              //add rbx, 0xFFFFFFFFFFFF9357
        rcx -= rdx;             //sub rcx, rdx
        rcx += rbx;             //add rcx, rbx
        rax = rcx;              //mov rax, rcx
        rax >>= 0x1D;           //shr rax, 0x1D
        rcx ^= rax;             //xor rcx, rax
        rbx = rcx;              //mov rbx, rcx
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rbx >>= 0x3A;           //shr rbx, 0x3A
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rbx ^= rcx;             //xor rbx, rcx
        rax ^= driver::read<uint64_t>(baseAddr + 0xB3491DC);            //xor rax, [0x00000000088BE543]
        rax = _byteswap_uint64(rax);            //bswap rax
        rbx *= driver::read<uint64_t>(rax + 0x15);              //imul rbx, [rax+0x15]
        rax = 0xD67810518E7F25DD;               //mov rax, 0xD67810518E7F25DD
        rbx *= rax;             //imul rbx, rax
        rax = rbx;              //mov rax, rbx
        rax >>= 0x5;            //shr rax, 0x05
        rbx ^= rax;             //xor rbx, rax
        rax = rbx;              //mov rax, rbx
        rax >>= 0xA;            //shr rax, 0x0A
        rbx ^= rax;             //xor rbx, rax
        rax = rbx;              //mov rax, rbx
        rax >>= 0x14;           //shr rax, 0x14
        rbx ^= rax;             //xor rbx, rax
        rax = rbx;              //mov rax, rbx
        rax >>= 0x28;           //shr rax, 0x28
        rbx ^= rax;             //xor rbx, rax
        return rbx;
    }

    uint64_t gamepass_decrypt_client_base(uint64_t client_info, uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rax = driver::read<uint64_t>(client_info + 0x1d5e68);
        if (!rax)
            return rax;
        r11 = ~peb;              //mov r11, gs:[rcx]
        rcx = r11;              //mov rcx, r11
        rcx = _rotl64(rcx, 0x34);               //rol rcx, 0x34
        //failed to translate: mov [rsp+0x100], r13
        rcx &= 0xF;
        switch (rcx) {
        case 0:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088C3A19]
            r13 = baseAddr + 0xDD05;                //lea r13, [0xFFFFFFFFFD5884D2]
            r12 = baseAddr + 0x33D36DEA;            //lea r12, [0x00000000312B159B]
            r15 = baseAddr + 0x16CBED5E;            //lea r15, [0x0000000014239503]
            rax ^= r11;             //xor rax, r11
            rax ^= r12;             //xor rax, r12
            rcx = r11;              //mov rcx, r11
            rcx *= r15;             //imul rcx, r15
            rax -= rcx;             //sub rax, rcx
            rcx = 0x2F44AFC8DA410289;               //mov rcx, 0x2F44AFC8DA410289
            rax *= rcx;             //imul rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = 0x31EA6C7327F2F48F;               //mov rcx, 0x31EA6C7327F2F48F
            rax *= rcx;             //imul rax, rcx
            rcx = r11;              //mov rcx, r11
            rcx = ~rcx;             //not rcx
            rcx ^= r13;             //xor rcx, r13
            rax -= rcx;             //sub rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xF;            //shr rcx, 0x0F
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1E;           //shr rcx, 0x1E
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x3C;           //shr rcx, 0x3C
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD57A586]
            rax -= rcx;             //sub rax, rcx
            return rax;
        }
        case 1:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349245);              //mov r9, [0x00000000088C354C]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD579ECD]
            rcx += 0x4C577047;              //add rcx, 0x4C577047
            rcx += r11;             //add rcx, r11
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x16;           //shr rcx, 0x16
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2C;           //shr rcx, 0x2C
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD579FD2]
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD57A09A]
            rcx += 0x673BCC74;              //add rcx, 0x673BCC74
            rcx += r11;             //add rcx, r11
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x14CEC15D15237845;               //mov rcx, 0x14CEC15D15237845
            rax *= rcx;             //imul rax, rcx
            rcx = 0xC6C8F26557A42C57;               //mov rcx, 0xC6C8F26557A42C57
            rax *= rcx;             //imul rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            return rax;
        }
        case 2:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349245);              //mov r9, [0x00000000088C30DF]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xC;            //shr rcx, 0x0C
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x18;           //shr rcx, 0x18
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x30;           //shr rcx, 0x30
            rax ^= rcx;             //xor rax, rcx
            rax -= r11;             //sub rax, r11
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = baseAddr + 0x40BA9587;            //lea rcx, [0x000000003E1232AC]
            rax += r11;             //add rax, r11
            rax += rcx;             //add rax, rcx
            rcx = 0xB820512AEEAE20F1;               //mov rcx, 0xB820512AEEAE20F1
            rax *= rcx;             //imul rax, rcx
            rcx = 0x5B4702F448FEE148;               //mov rcx, 0x5B4702F448FEE148
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD579CFD]
            rax += rcx;             //add rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x12;           //shr rcx, 0x12
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x24;           //shr rcx, 0x24
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 3:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088C2B99]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD579669]
            rax -= rcx;             //sub rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD5794EB]
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x13;           //shr rcx, 0x13
            rax ^= rcx;             //xor rax, rcx
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
            rcx = rax;              //mov rcx, rax
            rdx ^= r10;             //xor rdx, r10
            rcx >>= 0x26;           //shr rcx, 0x26
            rdx = ~rdx;             //not rdx
            rax ^= rcx;             //xor rax, rcx
            rax *= driver::read<uint64_t>(rdx + 0x7);               //imul rax, [rdx+0x07]
            rcx = r11;              //mov rcx, r11
            rcx = ~rcx;             //not rcx
            uintptr_t RSP_0x50;
            RSP_0x50 = baseAddr + 0x639AA956;               //lea rcx, [0x0000000060F2424A] : RSP+0x50
            rcx += RSP_0x50;                //add rcx, [rsp+0x50]
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xEF7AA6541B0960DD;               //mov rcx, 0xEF7AA6541B0960DD
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xAC44478E4E7E319F;               //mov rcx, 0xAC44478E4E7E319F
            rax *= rcx;             //imul rax, rcx
            rcx = 0x69DF0E377EDBC9BB;               //mov rcx, 0x69DF0E377EDBC9BB
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 4:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349245);              //mov r9, [0x00000000088C2721]
            rcx = 0x6B6B6FEB24A18CBC;               //mov rcx, 0x6B6B6FEB24A18CBC
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xE26425F12DE4CEB;                //mov rcx, 0xE26425F12DE4CEB
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x15;           //shr rcx, 0x15
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2A;           //shr rcx, 0x2A
            rax ^= rcx;             //xor rax, rcx
            rax += r11;             //add rax, r11
            rcx = 0xC6BD746DB1DF1B31;               //mov rcx, 0xC6BD746DB1DF1B31
            rax *= rcx;             //imul rax, rcx
            rax -= baseAddr;                //sub rax, [rbp-0x78] -- didn't find trace -> use base
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1;            //shr rcx, 0x01
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2;            //shr rcx, 0x02
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x4;            //shr rcx, 0x04
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x8;            //shr rcx, 0x08
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x10;           //shr rcx, 0x10
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x20;           //shr rcx, 0x20
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 5:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088C202B]
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rcx = r11 * 0xFFFFFFFFFFFFFFFE;                 //imul rcx, r11, 0xFFFFFFFFFFFFFFFE
            rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
            rax += rcx;             //add rax, rcx
            rdx ^= r10;             //xor rdx, r10
            rcx = baseAddr + 0x5F737FAA;            //lea rcx, [0x000000005CCB0B0A]
            rdx = ~rdx;             //not rdx
            rax += rcx;             //add rax, rcx
            rax *= driver::read<uint64_t>(rdx + 0x7);               //imul rax, [rdx+0x07]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x19;           //shr rcx, 0x19
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x32;           //shr rcx, 0x32
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD5789E9]
            rcx += 0x6987CC3C;              //add rcx, 0x6987CC3C
            rcx += r11;             //add rcx, r11
            rax += rcx;             //add rax, rcx
            rcx = 0xBEC2B746A9461603;               //mov rcx, 0xBEC2B746A9461603
            rax *= rcx;             //imul rax, rcx
            rcx = 0x7D25D991052F24B5;               //mov rcx, 0x7D25D991052F24B5
            rax += rcx;             //add rax, rcx
            rcx = 0x6B9AD86F193C7172;               //mov rcx, 0x6B9AD86F193C7172
            rax += rcx;             //add rax, rcx
            return rax;
        }
        case 6:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088C1BCC]
            r12 = baseAddr + 0x50AF1F4F;            //lea r12, [0x000000004E06A8C3]
            rax += r11;             //add rax, r11
            rcx = r11;              //mov rcx, r11
            rcx ^= r12;             //xor rcx, r12
            rax -= rcx;             //sub rax, rcx
            rcx = 0xFA37AFACEF63040B;               //mov rcx, 0xFA37AFACEF63040B
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xE15A50F0F0B4D5D9;               //mov rcx, 0xE15A50F0F0B4D5D9
            rax *= rcx;             //imul rax, rcx
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rcx = baseAddr + 0xEE8B;                //lea rcx, [0xFFFFFFFFFD5873F9]
            rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
            rcx -= r11;             //sub rcx, r11
            rax ^= rcx;             //xor rax, rcx
            rdx ^= r10;             //xor rdx, r10
            rdx = ~rdx;             //not rdx
            rax *= driver::read<uint64_t>(rdx + 0x7);               //imul rax, [rdx+0x07]
            rcx = 0x61E687AD8B6807D4;               //mov rcx, 0x61E687AD8B6807D4
            rax += rcx;             //add rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x15;           //shr rcx, 0x15
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2A;           //shr rcx, 0x2A
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 7:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088C16BB]
            r15 = baseAddr + 0xBEE4;                //lea r15, [0xFFFFFFFFFD584342]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD578105]
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x8DB3E6B3BD449D8;                //mov rcx, 0x8DB3E6B3BD449D8
            rax += rcx;             //add rax, rcx
            rcx = 0x7CFD8CC5318E532F;               //mov rcx, 0x7CFD8CC5318E532F
            rax *= rcx;             //imul rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x7;            //shr rcx, 0x07
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xE;            //shr rcx, 0x0E
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1C;           //shr rcx, 0x1C
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x38;           //shr rcx, 0x38
            rax ^= rcx;             //xor rax, rcx
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
            rcx = 0x6DE6E637B4DB68F1;               //mov rcx, 0x6DE6E637B4DB68F1
            rdx ^= r10;             //xor rdx, r10
            rdx = ~rdx;             //not rdx
            rax *= driver::read<uint64_t>(rdx + 0x7);               //imul rax, [rdx+0x07]
            rax *= rcx;             //imul rax, rcx
            rcx = r11;              //mov rcx, r11
            rcx -= r15;             //sub rcx, r15
            rax ^= rcx;             //xor rax, rcx
            rax -= r11;             //sub rax, r11
            return rax;
        }
        case 8:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349245);              //mov r9, [0x00000000088C127B]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1E;           //shr rcx, 0x1E
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x3C;           //shr rcx, 0x3C
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xD16E8EE163C9A6B;                //mov rcx, 0xD16E8EE163C9A6B
            rax *= rcx;             //imul rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xE;            //shr rcx, 0x0E
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1C;           //shr rcx, 0x1C
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x38;           //shr rcx, 0x38
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xA9C58221B90E7C46;               //mov rcx, 0xA9C58221B90E7C46
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x55F6ED3AB42B87A0;               //mov rcx, 0x55F6ED3AB42B87A0
            rax -= rcx;             //sub rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD577B56]
            rax += rcx;             //add rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x14;           //shr rcx, 0x14
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x28;           //shr rcx, 0x28
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 9:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088C0BC1]
            r12 = baseAddr + 0x6EC75C18;            //lea r12, [0x000000006C1ED581]
            rdx = baseAddr + 0xFCE2;                //lea rdx, [0xFFFFFFFFFD5874A5]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD5777B9]
            rdx *= r11;             //imul rdx, r11
            rdx -= rcx;             //sub rdx, rcx
            rcx = r11;              //mov rcx, r11
            rax += rdx;             //add rax, rdx
            rcx = ~rcx;             //not rcx
            rax ^= rcx;             //xor rax, rcx
            rax ^= r12;             //xor rax, r12
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x7;            //shr rcx, 0x07
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xE;            //shr rcx, 0x0E
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1C;           //shr rcx, 0x1C
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x38;           //shr rcx, 0x38
            rax ^= rcx;             //xor rax, rcx
            r15 = 0xB691FFD9C9D61B2E;               //mov r15, 0xB691FFD9C9D61B2E
            rax += r15;             //add rax, r15
            r15 = 0x89C1B16D1EAC4B85;               //mov r15, 0x89C1B16D1EAC4B85
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rax ^= r15;             //xor rax, r15
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = 0x272542A0099256AB;               //mov rcx, 0x272542A0099256AB
            rax *= rcx;             //imul rax, rcx
            return rax;
        }
        case 10:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088C06A1]
            r12 = baseAddr + 0x240D8AB0;            //lea r12, [0x000000002164FEF9]
            r13 = baseAddr + 0x24E689C1;            //lea r13, [0x00000000223DFDFE]
            rcx = r11 + r12 * 1;            //lea rcx, [r11+r12*1]
            rax ^= rcx;             //xor rax, rcx
            rdx = baseAddr + 0x3B21;                //lea rdx, [0xFFFFFFFFFD57ABC2]
            rcx = r11;              //mov rcx, r11
            rdx *= r11;             //imul rdx, r11
            rcx = ~rcx;             //not rcx
            rax += rdx;             //add rax, rdx
            rcx += r13;             //add rcx, r13
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x489A1BC87CDCD670;               //mov rcx, 0x489A1BC87CDCD670
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xA00242052F60AE53;               //mov rcx, 0xA00242052F60AE53
            rax ^= rcx;             //xor rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = 0xBDB64B81FECB6E7D;               //mov rcx, 0xBDB64B81FECB6E7D
            rax *= rcx;             //imul rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x28;           //shr rcx, 0x28
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 11:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088C01D0]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x15;           //shr rcx, 0x15
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2A;           //shr rcx, 0x2A
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xD3A53D9499733245;               //mov rcx, 0xD3A53D9499733245
            rax *= rcx;             //imul rax, rcx
            rcx = 0x72C2AC821062ABD1;               //mov rcx, 0x72C2AC821062ABD1
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD576A88]
            rax -= rcx;             //sub rax, rcx
            rax += 0xFFFFFFFFFFFF4954;              //add rax, 0xFFFFFFFFFFFF4954
            rax += r11;             //add rax, r11
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1;            //shr rcx, 0x01
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2;            //shr rcx, 0x02
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x4;            //shr rcx, 0x04
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x8;            //shr rcx, 0x08
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x10;           //shr rcx, 0x10
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x20;           //shr rcx, 0x20
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD576E20]
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr + 0x5B0222F4;            //lea rcx, [0x0000000058598D27]
            rcx *= r11;             //imul rcx, r11
            rax += rcx;             //add rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            return rax;
        }
        case 12:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088BFC65]
            r15 = baseAddr + 0x852;                 //lea r15, [0xFFFFFFFFFD57725F]
            rcx = 0xF7D4FABCE6FC022;                //mov rcx, 0xF7D4FABCE6FC022
            rax += rcx;             //add rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD5767C6]
            rax ^= rcx;             //xor rax, rcx
            rax -= rcx;             //sub rax, rcx
            rcx = 0x5C9D9DBA026E85B7;               //mov rcx, 0x5C9D9DBA026E85B7
            rax *= rcx;             //imul rax, rcx
            rcx = rax;              //mov rcx, rax
            rdx = r11;              //mov rdx, r11
            rcx >>= 0x21;           //shr rcx, 0x21
            rdx = ~rdx;             //not rdx
            rdx *= r15;             //imul rdx, r15
            rdx ^= rcx;             //xor rdx, rcx
            rax ^= rdx;             //xor rax, rdx
            rax += r11;             //add rax, r11
            return rax;
        }
        case 13:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088BF8A5]
            r15 = baseAddr + 0x12585A59;            //lea r15, [0x000000000FAFC0A6]
            rcx = r11;              //mov rcx, r11
            rcx = ~rcx;             //not rcx
            rcx ^= r15;             //xor rcx, r15
            rax += rcx;             //add rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x8;            //shr rcx, 0x08
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x10;           //shr rcx, 0x10
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x20;           //shr rcx, 0x20
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x11;           //shr rcx, 0x11
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x22;           //shr rcx, 0x22
            rax ^= rcx;             //xor rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = 0xA4979265BBC7E3D5;               //mov rcx, 0xA4979265BBC7E3D5
            rax *= rcx;             //imul rax, rcx
            rcx = r11;              //mov rcx, r11
            rcx = ~rcx;             //not rcx
            rcx -= baseAddr;                //sub rcx, [rbp-0x78] -- didn't find trace -> use base
            rcx -= 0x756FAD6E;              //sub rcx, 0x756FAD6E
            rcx ^= rax;             //xor rcx, rax
            rax = baseAddr + 0x78217335;            //lea rax, [0x000000007578D78C]
            rcx += r11;             //add rcx, r11
            rax += rcx;             //add rax, rcx
            rcx = 0xC20F4E2AD24BC517;               //mov rcx, 0xC20F4E2AD24BC517
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 14:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088BF329]
            r15 = baseAddr + 0x3CF1;                //lea r15, [0xFFFFFFFFFD579DC2]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x16;           //shr rcx, 0x16
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2C;           //shr rcx, 0x2C
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xAF96B7C88EDF2B75;               //mov rcx, 0xAF96B7C88EDF2B75
            rax *= rcx;             //imul rax, rcx
            rax ^= r11;             //xor rax, r11
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
            rdx ^= r10;             //xor rdx, r10
            rcx = r11 + r15 * 1;            //lea rcx, [r11+r15*1]
            rax += rcx;             //add rax, rcx
            rdx = ~rdx;             //not rdx
            rcx = 0x7B695E53D3CD7B7F;               //mov rcx, 0x7B695E53D3CD7B7F
            rax *= driver::read<uint64_t>(rdx + 0x7);               //imul rax, [rdx+0x07]
            rax *= rcx;             //imul rax, rcx
            rcx = 0x56A40B352BF2FDB7;               //mov rcx, 0x56A40B352BF2FDB7
            rax -= rcx;             //sub rax, rcx
            rcx = baseAddr + 0x32FFEB8B;            //lea rcx, [0x0000000030574B61]
            rcx = ~rcx;             //not rcx
            rcx *= r11;             //imul rcx, r11
            rax += rcx;             //add rax, rcx
            return rax;
        }
        case 15:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349245);             //mov r10, [0x00000000088BEDD6]
            r12 = baseAddr + 0x23AC2B6F;            //lea r12, [0x00000000210386ED]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD575955]
            rax -= rcx;             //sub rax, rcx
            rax += r11;             //add rax, r11
            rdx = r12;              //mov rdx, r12
            rdx = ~rdx;             //not rdx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rdx ^= r11;             //xor rdx, r11
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x17;           //shr rcx, 0x17
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2E;           //shr rcx, 0x2E
            rax ^= rcx;             //xor rax, rcx
            rax -= rdx;             //sub rax, rdx
            rcx = 0xAE9091426078C4DF;               //mov rcx, 0xAE9091426078C4DF
            rax *= rcx;             //imul rax, rcx
            rcx = 0x2E839B5F3DB76D2B;               //mov rcx, 0x2E839B5F3DB76D2B
            rax += rcx;             //add rax, rcx
            rcx = 0x632E9341FBDD9A7C;               //mov rcx, 0x632E9341FBDD9A7C
            rax -= rcx;             //sub rax, rcx
            return rax;
        }
        }
    };

    auto gamepass_decrypt_bone_base(uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rdx = driver::read<uint64_t>(baseAddr + 0x115F43D8);
        if (!rdx)
            return rdx;
        r11 = peb;              //mov r11, gs:[rax]
        rax = r11;              //mov rax, r11
        rax <<= 0x22;           //shl rax, 0x22
        rax = _byteswap_uint64(rax);            //bswap rax
        rax &= 0xF;
        switch (rax) {
        case 0:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349319);              //mov r9, [0x0000000005382282]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA038C7B]
            rdx -= rax;             //sub rdx, rax
            rax = 0xC98EF2FFB1E013D2;               //mov rax, 0xC98EF2FFB1E013D2
            rdx += 0xFFFFFFFFFFFFC795;              //add rdx, 0xFFFFFFFFFFFFC795
            rdx += r11;             //add rdx, r11
            rdx ^= rax;             //xor rdx, rax
            rdx ^= r11;             //xor rdx, r11
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
            rdx ^= r11;             //xor rdx, r11
            return rdx;
        }
        case 1:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x0000000005381D7D]
            rax = 0x311E3C7DD1297B69;               //mov rax, 0x311E3C7DD1297B69
            rdx *= rax;             //imul rdx, rax
            rcx = r11;              //mov rcx, r11
            rcx = ~rcx;             //not rcx
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr + 0x437D3D7F;            //lea rax, [0x000000003D80C623]
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
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA03886E]
            rax += 0x3B261317;              //add rax, 0x3B261317
            rax += r11;             //add rax, r11
            rdx += rax;             //add rdx, rax
            rax = 0x85B82AEE944DCF96;               //mov rax, 0x85B82AEE944DCF96
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA03897B]
            rdx += rax;             //add rdx, rax
            return rdx;
        }
        case 2:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349319);              //mov r9, [0x00000000053818B3]
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
            rdx += r11;             //add rdx, r11
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rdx ^= r11;             //xor rdx, r11
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
            r9 = driver::read<uint64_t>(baseAddr + 0xB349319);              //mov r9, [0x0000000005381470]
            r10 = baseAddr + 0x1314A155;            //lea r10, [0x000000000D182294]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA03805F]
            rdx -= rax;             //sub rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1F;           //shr rax, 0x1F
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x3E;           //shr rax, 0x3E
            rdx ^= rax;             //xor rdx, rax
            rdx ^= r11;             //xor rdx, r11
            rax = r10;              //mov rax, r10
            rax -= r11;             //sub rax, r11
            rdx ^= rax;             //xor rdx, rax
            rax = 0xD5A4D08183955257;               //mov rax, 0xD5A4D08183955257
            rdx *= rax;             //imul rdx, rax
            rax = 0x8DC8AE43913090FA;               //mov rax, 0x8DC8AE43913090FA
            rdx ^= rax;             //xor rdx, rax
            return rdx;
        }
        case 4:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x0000000005381171]
            rax = 0xF7A45523CB2EF07F;               //mov rax, 0xF7A45523CB2EF07F
            rdx ^= rax;             //xor rdx, rax
            rdx -= r11;             //sub rdx, r11
            rdx -= r11;             //sub rdx, r11
            rdx -= r11;             //sub rdx, r11
            rax = rdx;              //mov rax, rdx
            rax >>= 0x14;           //shr rax, 0x14
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x28;           //shr rax, 0x28
            rdx ^= rax;             //xor rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA037AA3]
            rax += 0x8F29;          //add rax, 0x8F29
            rax += r11;             //add rax, r11
            rdx ^= rax;             //xor rdx, rax
            rax = 0xD43375ADC5407E51;               //mov rax, 0xD43375ADC5407E51
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 5:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349319);              //mov r9, [0x0000000005380CC3]
            r12 = baseAddr + 0x12426297;            //lea r12, [0x000000000C45DC1F]
            rax = 0x7C5DF0A12057BE6;                //mov rax, 0x7C5DF0A12057BE6
            rdx -= rax;             //sub rdx, rax
            rax = 0x83F8FC0408B5D1AB;               //mov rax, 0x83F8FC0408B5D1AB
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr + 0x158DE932;            //lea rax, [0x000000000F91611D]
            rax = ~rax;             //not rax
            rax *= r11;             //imul rax, r11
            rdx += rax;             //add rdx, rax
            rax = r11;              //mov rax, r11
            rax *= r12;             //imul rax, r12
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA037734]
            rax += 0x5541;          //add rax, 0x5541
            rax += r11;             //add rax, r11
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
            rax ^= r9;              //xor rax, r9
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = 0x3F31D045C89ED8C5;               //mov rax, 0x3F31D045C89ED8C5
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 6:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x0000000005380726]
            r12 = baseAddr + 0x6DA9DAD4;            //lea r12, [0x0000000067AD4EC9]
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
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA037191]
            rax += 0x144205B7;              //add rax, 0x144205B7
            rax += r11;             //add rax, r11
            rdx ^= rax;             //xor rdx, rax
            rax = 0x80C6B6FC948F6729;               //mov rax, 0x80C6B6FC948F6729
            rdx *= rax;             //imul rdx, rax
            rax = 0x31DF20582505A415;               //mov rax, 0x31DF20582505A415
            rdx += rax;             //add rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rdx += r12;             //add rdx, r12
            rcx = r11;              //mov rcx, r11
            rcx = ~rcx;             //not rcx
            rdx += rcx;             //add rdx, rcx
            return rdx;
        }
        case 7:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x0000000005380338]
            r13 = baseAddr + 0x4354;                //lea r13, [0xFFFFFFFFFA03B360]
            rdx ^= r11;             //xor rdx, r11
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
            rax = r11;              //mov rax, r11
            rax = ~rax;             //not rax
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rax *= r13;             //imul rax, r13
            rcx ^= r10;             //xor rcx, r10
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx += rax;             //add rdx, rax
            rdx *= driver::read<uint64_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
            return rdx;
        }
        case 8:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x000000000537FE9B]
            r12 = baseAddr + 0x7D814959;            //lea r12, [0x000000007784B4C8]
            rdx -= r11;             //sub rdx, r11
            rax = 0xEDC13D6B57B6E285;               //mov rax, 0xEDC13D6B57B6E285
            rdx *= rax;             //imul rdx, rax
            rax = r11;              //mov rax, r11
            rax ^= r12;             //xor rax, r12
            rax += r11;             //add rax, r11
            rdx += rax;             //add rdx, rax
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx *= driver::read<uint64_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x21;           //shr rax, 0x21
            rdx ^= rax;             //xor rdx, rax
            rdx += r11;             //add rdx, r11
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA036A12]
            rdx ^= rax;             //xor rdx, rax
            return rdx;
        }
        case 9:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349319);              //mov r9, [0x000000000537FB59]
            rax = rdx;              //mov rax, rdx
            rax >>= 0xB;            //shr rax, 0x0B
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x16;           //shr rax, 0x16
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x2C;           //shr rax, 0x2C
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA0363F0]
            rdx ^= rax;             //xor rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
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
            rax -= r11;             //sub rax, r11
            rax -= baseAddr;                //sub rax, [rsp+0xD8] -- didn't find trace -> use base
            rdx += rax;             //add rdx, rax
            rax = 0x5E76F88978AFE528;               //mov rax, 0x5E76F88978AFE528
            rdx += rax;             //add rdx, rax
            rax = 0x33557C5CEFBE234B;               //mov rax, 0x33557C5CEFBE234B
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 10:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x000000000537F633]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA0361A7]
            rdx -= rax;             //sub rdx, rax
            rcx = rdx;              //mov rcx, rdx
            rcx >>= 0x27;           //shr rcx, 0x27
            rcx ^= rdx;             //xor rcx, rdx
            rdx = baseAddr + 0x9688;                //lea rdx, [0xFFFFFFFFFA03F723]
            rdx *= r11;             //imul rdx, r11
            rdx += rcx;             //add rdx, rcx
            rax = rdx;              //mov rax, rdx
            rax >>= 0x13;           //shr rax, 0x13
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x26;           //shr rax, 0x26
            rdx ^= rax;             //xor rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = 0x3331EF2FFF7DD801;               //mov rax, 0x3331EF2FFF7DD801
            rdx *= rax;             //imul rdx, rax
            rax = 0x2130706D6228E017;               //mov rax, 0x2130706D6228E017
            rdx ^= rax;             //xor rdx, rax
            return rdx;
        }
        case 11:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x000000000537F158]
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rax = baseAddr + 0x1E13DCA3;            //lea rax, [0x000000001817371B]
            rax = ~rax;             //not rax
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rax += r11;             //add rax, r11
            rcx ^= r10;             //xor rcx, r10
            rdx += rax;             //add rdx, rax
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx *= driver::read<uint64_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA035A4A]
            rax += 0x9D9E;          //add rax, 0x9D9E
            rax += r11;             //add rax, r11
            rdx += rax;             //add rdx, rax
            rax = r11;              //mov rax, r11
            rax -= baseAddr;                //sub rax, [rsp+0xD8] -- didn't find trace -> use base
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
            rcx = baseAddr + 0x7C2A0085;            //lea rcx, [0x00000000762D5B93]
            rcx = ~rcx;             //not rcx
            rcx *= r11;             //imul rcx, r11
            rax = rdx;              //mov rax, rdx
            rax >>= 0x22;           //shr rax, 0x22
            rcx ^= rax;             //xor rcx, rax
            rdx ^= rcx;             //xor rdx, rcx
            return rdx;
        }
        case 12:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB349319);              //mov r9, [0x000000000537ED03]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rdx -= r11;             //sub rdx, r11
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x000000000537E86C]
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
            rcx ^= r10;             //xor rcx, r10
            rdx += r11;             //add rdx, r11
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx *= driver::read<uint64_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
            rcx = baseAddr + 0x7FFA;                //lea rcx, [0xFFFFFFFFFA03D49F]
            rax = 0xEA5C4AF83EEC98D;                //mov rax, 0xEA5C4AF83EEC98D
            rdx += rax;             //add rdx, rax
            rax = rcx;              //mov rax, rcx
            rax = ~rax;             //not rax
            rax ^= r11;             //xor rax, r11
            rdx ^= rax;             //xor rdx, rax
            rax = 0x58CCD785809FBA65;               //mov rax, 0x58CCD785809FBA65
            rdx *= rax;             //imul rdx, rax
            rax = 0xCB1252FFDD097729;               //mov rax, 0xCB1252FFDD097729
            rdx *= rax;             //imul rdx, rax
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA03510F]
            rax += 0x1CFB;          //add rax, 0x1CFB
            rax += r11;             //add rax, r11
            rdx += rax;             //add rdx, rax
            return rdx;
        }
        case 14:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x000000000537E2B4]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1C;           //shr rax, 0x1C
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x38;           //shr rax, 0x38
            rax ^= rdx;             //xor rax, rdx
            rdx = baseAddr;                 //lea rdx, [0xFFFFFFFFFA034C42]
            rax -= rdx;             //sub rax, rdx
            rdx = r11 + 0xffffffffd3bc8867;                 //lea rdx, [r11-0x2C437799]
            rdx += rax;             //add rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA034B50]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB349319);             //mov r10, [0x000000000537DE33]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x25;           //shr rax, 0x25
            rdx ^= rax;             //xor rdx, rax
            rdx -= r11;             //sub rdx, r11
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA03489D]
            rax += 0x953;           //add rax, 0x953
            rax += r11;             //add rax, r11
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx ^= rax;             //xor rdx, rax
            rdx *= driver::read<uint64_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
            rax = 0xEDC186E4F45D82CF;               //mov rax, 0xEDC186E4F45D82CF
            rdx *= rax;             //imul rdx, rax
            rdx -= r11;             //sub rdx, r11
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFA03479C]
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

    uintptr_t gamepass_get_bone_index(uint32_t bone_index, uint64_t baseAddr)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rbx = bone_index;
        rcx = rbx * 0x13C8;
        rax = 0xD8CE01BF28E39A45;               //mov rax, 0xD8CE01BF28E39A45
        rbx = baseAddr;                 //lea rbx, [0xFFFFFFFFFD527F2E]
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
        rax = driver::read<uint16_t>(rcx + rbx * 1 + 0xA2F4330);                //movzx eax, word ptr [rcx+rbx*1+0xA2F4330]
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
        rsi = driver::read<uint16_t>(rcx + rbx * 1 + 0xA302F60);                //movsx esi, word ptr [rcx+rbx*1+0xA302F60]
        return rsi;
    }
}