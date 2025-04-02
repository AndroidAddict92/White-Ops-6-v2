namespace BO6 {
    static uint32_t refdef = 0xCDDE140;
    static uint32_t name_array = 0xCE2CE48;
    static uint32_t name_array_pos = 0x1838;
    static uint32_t name_size = 0xC8;
    static uint32_t loot_ptr = 0xE5A2B20;
    static uint32_t loot_pos = 0x170; // not sure
    static uint32_t loot_valid = 0x124; // not sure
    static uint32_t loot_valid_supply = 0x126; // not sure
    static uint32_t loot_size = 0x1F0; // not sure
    static uint32_t camera_base = 0xCAFFE70;
    static uint32_t camera_pos = 0x204;
    static uint32_t local_index = 0x1B16D0;
    static uint32_t local_index_pos = 0x34C;
    static uint32_t recoil = 0x79624;
    static uint32_t game_mode = 0xB8B7B98;
    static uint32_t weapon_definitions = 0xCCAD550;
    static uint32_t distribute = 0x10593A18;
    static uint32_t visible = 0x79014;
    static uint32_t scoreboard = 0xA1B70;
    static uint32_t scoreboard_size = 0x90;


    namespace bone {
        static uintptr_t base_pos = 0x1C5D08;
        static uintptr_t index_struct_size = 0x1A0;
    };

    namespace player {
        static uint32_t size = 0x20E8;
        static uint32_t valid = 0x839;
        static uint32_t pos = 0x920;
        static uint32_t team = 0xEA4;
        static uint32_t stance = 0x131; // - 0x9 untested - if this works, its thanks to @curtcohbain on the forums
        static uint32_t weapon_index = 0xF52;
        static uint32_t dead_1 = 0x0;
        static uint32_t dead_2 = 0x0;
        static uint32_t local_entity = 0x740E8;
        static uint32_t entity_size = 0x538;
        static uint32_t entity_type = 0x8C;
        static uint32_t entity_valid = 0x24;
        static uint32_t entity_index = 0x84;
        static uint32_t entity_pos = entity_type + 0x1C;
    }
}

namespace BO6 {
    uint64_t bnet_decrypt_client_active()
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rax = driver::read<uint64_t>(client_active + 0xb8ae6f8);
        if (!rax)
            return rax;
        rbx = peb;              //mov rbx, gs:[rcx]
        //failed to translate: mov [rsp+0x68], rdi
        rcx = rbx;              //mov rcx, rbx
        //failed to translate: mov [rsp+0x60], r12
        rcx = _rotr64(rcx, 0x17);               //ror rcx, 0x17
        //failed to translate: mov [rsp+0x58], r13
        rcx &= 0xF;
        switch (rcx) {
        case 0:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x0000000009898E5F]
            r14 = baseAddr + 0xBB5C;                //lea r14, [0xFFFFFFFFFE23B59D]
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = r14;              //mov rcx, r14
            rcx = ~rcx;             //not rcx
            rcx ^= rbx;             //xor rcx, rbx
            rax -= rcx;             //sub rax, rcx
            rcx = baseAddr + 0x294D6C6B;            //lea rcx, [0x00000000277062D1]
            rcx = ~rcx;             //not rcx
            rcx += rbx;             //add rcx, rbx
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xC;            //shr rcx, 0x0C
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x18;           //shr rcx, 0x18
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x30;           //shr rcx, 0x30
            rax ^= rcx;             //xor rax, rcx
            rax -= rbx;             //sub rax, rbx
            rcx = 0x34122B087AE11FEB;               //mov rcx, 0x34122B087AE11FEB
            rax *= rcx;             //imul rax, rcx
            rcx = 0xE5727D28FB2ABA91;               //mov rcx, 0xE5727D28FB2ABA91
            rax *= rcx;             //imul rax, rcx
            rcx = 0x689B98FA6B51749A;               //mov rcx, 0x689B98FA6B51749A
            rax += rcx;             //add rax, rcx
            return rax;
        }
        case 1:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x0000000009898932]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22F508]
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = 0xFFFFFFFFFFFFB77A;               //mov rcx, 0xFFFFFFFFFFFFB77A
            rcx -= rbx;             //sub rcx, rbx
            rcx -= r11;             //sub rcx, r11
            rax += rcx;             //add rax, rcx
            rcx = 0xBC5D15BA3006E97D;               //mov rcx, 0xBC5D15BA3006E97D
            rax *= rcx;             //imul rax, rcx
            rcx = 0x11F8128AE12F52F0;               //mov rcx, 0x11F8128AE12F52F0
            rax ^= rcx;             //xor rax, rcx
            rax -= r11;             //sub rax, r11
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x24;           //shr rcx, 0x24
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 2:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB669417);              //mov r9, [0x0000000009898582]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22F158]
            r14 = 0xDA06A37913A7A54C;               //mov r14, 0xDA06A37913A7A54C
            rax += r14;             //add rax, r14
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x15;           //shr rcx, 0x15
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2A;           //shr rcx, 0x2A
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xD87695EDA188F96D;               //mov rcx, 0xD87695EDA188F96D
            rax *= rcx;             //imul rax, rcx
            rax += rbx;             //add rax, rbx
            rax -= r11;             //sub rax, r11
            rcx = 0x2AB0ED5261B0236E;               //mov rcx, 0x2AB0ED5261B0236E
            rax += rcx;             //add rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xD;            //shr rcx, 0x0D
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1A;           //shr rcx, 0x1A
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x34;           //shr rcx, 0x34
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 3:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB669417);              //mov r9, [0x0000000009898155]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22ED2B]
            r15 = baseAddr + 0xB5E6;                //lea r15, [0xFFFFFFFFFE23A306]
            rcx = rbx;              //mov rcx, rbx
            rcx = ~rcx;             //not rcx
            rcx ^= r15;             //xor rcx, r15
            rax += rcx;             //add rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = r11 + 0xaa40;             //lea rcx, [r11+0xAA40]
            rcx += rbx;             //add rcx, rbx
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x1285D6CF00544E0D;               //mov rcx, 0x1285D6CF00544E0D
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x20;           //shr rcx, 0x20
            rcx ^= rax;             //xor rcx, rax
            rax = 0x975798BE487DA122;               //mov rax, 0x975798BE487DA122
            rax += rcx;             //add rax, rcx
            rax += r11;             //add rax, r11
            rcx = 0xC9284E5D67F4CE4B;               //mov rcx, 0xC9284E5D67F4CE4B
            rax *= rcx;             //imul rax, rcx
            return rax;
        }
        case 4:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x0000000009897D66]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22E93C]
            r13 = baseAddr + 0xC499;                //lea r13, [0xFFFFFFFFFE23ADCA]
            r12 = baseAddr + 0x4693C75B;            //lea r12, [0x0000000044B6B080]
            rcx = 0x3F776FE9F5E8EAA7;               //mov rcx, 0x3F776FE9F5E8EAA7
            rax *= rcx;             //imul rax, rcx
            rcx = 0x65C99EAA8836C26E;               //mov rcx, 0x65C99EAA8836C26E
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x213CE7180F3DDBAF;               //mov rcx, 0x213CE7180F3DDBAF
            rax -= rbx;             //sub rax, rbx
            rax += r13;             //add rax, r13
            rax ^= rcx;             //xor rax, rcx
            rdx = rax;              //mov rdx, rax
            rdx >>= 0x21;           //shr rdx, 0x21
            rax ^= rdx;             //xor rax, rdx
            rcx = rbx;              //mov rcx, rbx
            rcx *= r12;             //imul rcx, r12
            rax -= rcx;             //sub rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = rbx;              //mov rcx, rbx
            rcx -= r11;             //sub rcx, r11
            rcx += 0xFFFFFFFF904A8AFE;              //add rcx, 0xFFFFFFFF904A8AFE
            rax += rcx;             //add rax, rcx
            return rax;
        }
        case 5:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x0000000009897950]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22E521]
            r15 = baseAddr + 0x320E;                //lea r15, [0xFFFFFFFFFE231724]
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
            rcx = 0xE93A1E9051733D75;               //mov rcx, 0xE93A1E9051733D75
            rax *= rcx;             //imul rax, rcx
            rax ^= rbx;             //xor rax, rbx
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
            rcx = r15;              //mov rcx, r15
            rcx -= rbx;             //sub rcx, rbx
            rdx ^= r10;             //xor rdx, r10
            rax ^= rcx;             //xor rax, rcx
            rdx = ~rdx;             //not rdx
            rax *= driver::read<uint64_t>(rdx + 0x11);              //imul rax, [rdx+0x11]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x3;            //shr rcx, 0x03
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x6;            //shr rcx, 0x06
            rax ^= rcx;             //xor rax, rcx
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
            return rax;
        }
        case 6:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB669417);              //mov r9, [0x000000000989748D]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22E063]
            rax -= rbx;             //sub rax, rbx
            rcx = 0x4E9678EF019565DF;               //mov rcx, 0x4E9678EF019565DF
            rax -= rcx;             //sub rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x8;            //shr rcx, 0x08
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x10;           //shr rcx, 0x10
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x20;           //shr rcx, 0x20
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x3DA84F7AEF898283;               //mov rcx, 0x3DA84F7AEF898283
            rax *= rcx;             //imul rax, rcx
            rcx = 0x1C5E0EEE229E67D2;               //mov rcx, 0x1C5E0EEE229E67D2
            rax += rcx;             //add rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rax += r11;             //add rax, r11
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x16;           //shr rcx, 0x16
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2C;           //shr rcx, 0x2C
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 7:
        {
            r11 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r11, [0x0000000009896FF9]
            r14 = baseAddr + 0x22522DDB;            //lea r14, [0x00000000207509A5]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x26;           //shr rcx, 0x26
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xE84F1C193188C445;               //mov rcx, 0xE84F1C193188C445
            rax *= rcx;             //imul rax, rcx
            rcx = 0xEA7DE66ECAE6F5AB;               //mov rcx, 0xEA7DE66ECAE6F5AB
            rax *= rcx;             //imul rax, rcx
            rcx = 0x53F3271FF8E86FBE;               //mov rcx, 0x53F3271FF8E86FBE
            rax += rcx;             //add rax, rcx
            r8 = baseAddr + 0x7DB4F5FB;             //lea r8, [0x000000007BD7CE65]
            r8 += rax;              //add r8, rax
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r11;             //xor rcx, r11
            rdx = rbx;              //mov rdx, rbx
            rdx = ~rdx;             //not rdx
            rcx = ~rcx;             //not rcx
            rdx ^= r14;             //xor rdx, r14
            rdx += rbx;             //add rdx, rbx
            r8 += rdx;              //add r8, rdx
            rax = r8;               //mov rax, r8
            rax >>= 0x25;           //shr rax, 0x25
            rax ^= r8;              //xor rax, r8
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            return rax;
        }
        case 8:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB669417);              //mov r9, [0x0000000009896B8B]
            r11 = baseAddr + 0x569C2F33;            //lea r11, [0x0000000054BF068F]
            rcx = 0xDFA619B7A6F44089;               //mov rcx, 0xDFA619B7A6F44089
            rax *= rcx;             //imul rax, rcx
            rcx = rbx;              //mov rcx, rbx
            rcx ^= r11;             //xor rcx, r11
            rax += rcx;             //add rax, rcx
            rax ^= rbx;             //xor rax, rbx
            uintptr_t RSP_0x30;
            RSP_0x30 = 0xF7E9D0C7DB65D6A5;          //mov rcx, 0xF7E9D0C7DB65D6A5 : RBP+0x30
            rax ^= RSP_0x30;                //xor rax, [rbp+0x30]
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rax -= rbx;             //sub rax, rbx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x15;           //shr rcx, 0x15
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2A;           //shr rcx, 0x2A
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x6C0FBEE7C1E8E756;               //mov rcx, 0x6C0FBEE7C1E8E756
            rax -= rcx;             //sub rax, rcx
            return rax;
        }
        case 9:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB669417);              //mov r9, [0x000000000989675A]
            rcx = 0xDA65CF0CF67B373A;               //mov rcx, 0xDA65CF0CF67B373A
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x15;           //shr rcx, 0x15
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2A;           //shr rcx, 0x2A
            rax ^= rcx;             //xor rax, rcx
            rax += rbx;             //add rax, rbx
            rax ^= rbx;             //xor rax, rbx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xE;            //shr rcx, 0x0E
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x1C;           //shr rcx, 0x1C
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x38;           //shr rcx, 0x38
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xDDB4C38A54062BD1;               //mov rcx, 0xDDB4C38A54062BD1
            rax ^= rcx;             //xor rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = 0xBCEBBD2C4FEFC489;               //mov rcx, 0xBCEBBD2C4FEFC489
            rax *= rcx;             //imul rax, rcx
            return rax;
        }
        case 10:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x00000000098962A4]
            r12 = baseAddr + 0x7721;                //lea r12, [0xFFFFFFFFFE234590]
            rcx = baseAddr + 0x524D;                //lea rcx, [0xFFFFFFFFFE231E57]
            rcx = ~rcx;             //not rcx
            rcx -= rbx;             //sub rcx, rbx
            rax += rcx;             //add rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x6;            //shr rcx, 0x06
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xC;            //shr rcx, 0x0C
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x18;           //shr rcx, 0x18
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x30;           //shr rcx, 0x30
            rax ^= rcx;             //xor rax, rcx
            rax -= rbx;             //sub rax, rbx
            rax += r12;             //add rax, r12
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
            rcx = rax;              //mov rcx, rax
            rdx ^= r10;             //xor rdx, r10
            rcx >>= 0x24;           //shr rcx, 0x24
            rdx = ~rdx;             //not rdx
            rax ^= rcx;             //xor rax, rcx
            rax *= driver::read<uint64_t>(rdx + 0x11);              //imul rax, [rdx+0x11]
            rcx = 0x947C86A82EF977E3;               //mov rcx, 0x947C86A82EF977E3
            rax *= rcx;             //imul rax, rcx
            rcx = 0x666FF2F895BC99A;                //mov rcx, 0x666FF2F895BC99A
            rax += rcx;             //add rax, rcx
            rcx = 0x1445685305B2FC7C;               //mov rcx, 0x1445685305B2FC7C
            rax -= rcx;             //sub rax, rcx
            return rax;
        }
        case 11:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB669417);              //mov r9, [0x0000000009895D21]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22C8F2]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x20;           //shr rcx, 0x20
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x492E0BEC379EABCB;               //mov rcx, 0x492E0BEC379EABCB
            rax *= rcx;             //imul rax, rcx
            rax -= r11;             //sub rax, r11
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r9;              //xor rcx, r9
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = r11 * 0xFFFFFFFFFFFFFFFE;                 //imul rcx, r11, 0xFFFFFFFFFFFFFFFE
            rax += rcx;             //add rax, rcx
            rax ^= rbx;             //xor rax, rbx
            rax -= r11;             //sub rax, r11
            rax += 0xFFFFFFFFFFFF8EE5;              //add rax, 0xFFFFFFFFFFFF8EE5
            rax += rbx;             //add rax, rbx
            return rax;
        }
        case 12:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x000000000989591F]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22C4F5]
            rcx = rbx + r11 * 1;            //lea rcx, [rbx+r11*1]
            rax -= rcx;             //sub rax, rcx
            rcx = baseAddr + 0xFDF4;                //lea rcx, [0xFFFFFFFFFE23C203]
            rcx -= rbx;             //sub rcx, rbx
            rax += rcx;             //add rax, rcx
            rcx = 0x4B5785F6067B547F;               //mov rcx, 0x4B5785F6067B547F
            rax *= rcx;             //imul rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x15;           //shr rcx, 0x15
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2A;           //shr rcx, 0x2A
            rax ^= rcx;             //xor rax, rcx
            rcx = 0x63677938B9EDDE4D;               //mov rcx, 0x63677938B9EDDE4D
            rax ^= rcx;             //xor rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rax -= rbx;             //sub rax, rbx
            return rax;
        }
        case 13:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x00000000098955A4]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22C17A]
            rdx = rbx;              //mov rdx, rbx
            rdx = ~rdx;             //not rdx
            rcx = baseAddr + 0x18FEF1C3;            //lea rcx, [0x000000001721AF8F]
            rdx += rcx;             //add rdx, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x25;           //shr rcx, 0x25
            rdx ^= rcx;             //xor rdx, rcx
            rax ^= rdx;             //xor rax, rdx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = 0xF70F8665D40E2665;               //mov rcx, 0xF70F8665D40E2665
            rax ^= r11;             //xor rax, r11
            rax *= rcx;             //imul rax, rcx
            rcx = 0x33521DE3923FE8DA;               //mov rcx, 0x33521DE3923FE8DA
            rax += rcx;             //add rax, rcx
            rax -= r11;             //sub rax, r11
            rcx = 0x8BC475B5AD8098B2;               //mov rcx, 0x8BC475B5AD8098B2
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 14:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x0000000009895116]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22BCEC]
            r12 = baseAddr + 0x6E321334;            //lea r12, [0x000000006C54D015]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xA;            //shr rcx, 0x0A
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x14;           //shr rcx, 0x14
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x28;           //shr rcx, 0x28
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0xC;            //shr rcx, 0x0C
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x18;           //shr rcx, 0x18
            rax ^= rcx;             //xor rax, rcx
            rdx = rbx + 0x1;                //lea rdx, [rbx+0x01]
            rdx *= r12;             //imul rdx, r12
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x30;           //shr rcx, 0x30
            rcx ^= rax;             //xor rcx, rax
            rax = 0x1B71D98EA059DF4A;               //mov rax, 0x1B71D98EA059DF4A
            rax += rdx;             //add rax, rdx
            rax += rcx;             //add rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rax -= r11;             //sub rax, r11
            rcx = 0xCB581E7AA959ED37;               //mov rcx, 0xCB581E7AA959ED37
            rax *= rcx;             //imul rax, rcx
            return rax;
        }
        case 15:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB669417);             //mov r10, [0x0000000009894C18]
            r11 = baseAddr;                 //lea r11, [0xFFFFFFFFFE22B7EE]
            uintptr_t RSP_0xFFFFFFFFFFFFFFA8;
            RSP_0xFFFFFFFFFFFFFFA8 = 0x2E522CA8E96EF3D9;            //mov rcx, 0x2E522CA8E96EF3D9 : RBP+0xFFFFFFFFFFFFFFA8
            rax ^= RSP_0xFFFFFFFFFFFFFFA8;          //xor rax, [rbp-0x58]
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x11);              //imul rax, [rcx+0x11]
            rcx = 0x9F60910D1D81A995;               //mov rcx, 0x9F60910D1D81A995
            rax *= rcx;             //imul rax, rcx
            rcx = 0xFFFFFFFF9A86BC8E;               //mov rcx, 0xFFFFFFFF9A86BC8E
            rcx -= rbx;             //sub rcx, rbx
            rcx -= r11;             //sub rcx, r11
            rax += rcx;             //add rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x23;           //shr rcx, 0x23
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x24;           //shr rcx, 0x24
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x23;           //shr rcx, 0x23
            rax ^= rcx;             //xor rax, rcx
            rcx = rbx;              //mov rcx, rbx
            rcx = ~rcx;             //not rcx
            rcx -= r11;             //sub rcx, r11
            rcx += 0xFFFFFFFFE60B78D4;              //add rcx, 0xFFFFFFFFE60B78D4
            rax += rcx;             //add rax, rcx
            return rax;
        }
        }
    }

    uint64_t bnet_decrypt_client_info(uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rbx = driver::read<uint64_t>(baseAddr + 0xCDD9168);
        if (!rbx)
            return rbx;
        rcx = peb;              //mov rcx, gs:[rax]
        //failed to trace. base: 00007FF7C59F0000 It's possibly wrong   rdx = 0000000000000065
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
        rax ^= driver::read<uint64_t>(baseAddr + 0xB66938C);            //xor rax, [0x0000000008B6E513]
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

    uint64_t bnet_decrypt_client_base(uint64_t client_info, uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rax = driver::read<uint64_t>(client_info + 0x1d7988);
        if (!rax)
            return rax;
        r11 = ~peb;              //mov r11, gs:[rcx]
        //failed to translate: mov [rsp+0x138], r12
        rcx = r11;              //mov rcx, r11
        rcx = _rotl64(rcx, 0x34);               //rol rcx, 0x34
        //failed to translate: mov [rsp+0x100], r13
        rcx &= 0xF;
        switch (rcx) {
        case 0:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B739E9]
            r13 = baseAddr + 0xDD05;                //lea r13, [0xFFFFFFFFFD5182F2]
            r12 = baseAddr + 0x33D36DEA;            //lea r12, [0x00000000312413BB]
            r15 = baseAddr + 0x16CBED5E;            //lea r15, [0x00000000141C9323]
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
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD50A3A6]
            rax -= rcx;             //sub rax, rcx
            return rax;
        }
        case 1:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB6693F5);              //mov r9, [0x0000000008B7351C]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD509CED]
            rcx += 0x4C577047;              //add rcx, 0x4C577047
            rcx += r11;             //add rcx, r11
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x16;           //shr rcx, 0x16
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x2C;           //shr rcx, 0x2C
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD509DF2]
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD509EBA]
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
            r9 = driver::read<uint64_t>(baseAddr + 0xB6693F5);              //mov r9, [0x0000000008B730AF]
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
            rcx = baseAddr + 0x40BA9587;            //lea rcx, [0x000000003E0B30CC]
            rax += r11;             //add rax, r11
            rax += rcx;             //add rax, rcx
            rcx = 0xB820512AEEAE20F1;               //mov rcx, 0xB820512AEEAE20F1
            rax *= rcx;             //imul rax, rcx
            rcx = 0x5B4702F448FEE148;               //mov rcx, 0x5B4702F448FEE148
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD509B1D]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B72B69]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD509489]
            rax -= rcx;             //sub rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD50930B]
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
            RSP_0x50 = baseAddr + 0x639AA956;               //lea rcx, [0x0000000060EB406A] : RSP+0x50
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
            r9 = driver::read<uint64_t>(baseAddr + 0xB6693F5);              //mov r9, [0x0000000008B726F1]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B71FFB]
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rcx = r11 * 0xFFFFFFFFFFFFFFFE;                 //imul rcx, r11, 0xFFFFFFFFFFFFFFFE
            rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
            rax += rcx;             //add rax, rcx
            rdx ^= r10;             //xor rdx, r10
            rcx = baseAddr + 0x5F737FAA;            //lea rcx, [0x000000005CC4092A]
            rdx = ~rdx;             //not rdx
            rax += rcx;             //add rax, rcx
            rax *= driver::read<uint64_t>(rdx + 0x7);               //imul rax, [rdx+0x07]
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x19;           //shr rcx, 0x19
            rax ^= rcx;             //xor rax, rcx
            rcx = rax;              //mov rcx, rax
            rcx >>= 0x32;           //shr rcx, 0x32
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD508809]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B71B9C]
            r12 = baseAddr + 0x50AF1F4F;            //lea r12, [0x000000004DFFA6E3]
            rax += r11;             //add rax, r11
            rcx = r11;              //mov rcx, r11
            rcx ^= r12;             //xor rcx, r12
            rax -= rcx;             //sub rax, rcx
            rcx = 0xFA37AFACEF63040B;               //mov rcx, 0xFA37AFACEF63040B
            rax ^= rcx;             //xor rax, rcx
            rcx = 0xE15A50F0F0B4D5D9;               //mov rcx, 0xE15A50F0F0B4D5D9
            rax *= rcx;             //imul rax, rcx
            rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
            rcx = baseAddr + 0xEE8B;                //lea rcx, [0xFFFFFFFFFD517219]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B7168B]
            r15 = baseAddr + 0xBEE4;                //lea r15, [0xFFFFFFFFFD514162]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD507F25]
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
            r9 = driver::read<uint64_t>(baseAddr + 0xB6693F5);              //mov r9, [0x0000000008B7124B]
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
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD507976]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B70B91]
            r12 = baseAddr + 0x6EC75C18;            //lea r12, [0x000000006C17D3A1]
            rdx = baseAddr + 0xFCE2;                //lea rdx, [0xFFFFFFFFFD5172C5]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD5075D9]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B70671]
            r12 = baseAddr + 0x240D8AB0;            //lea r12, [0x00000000215DFD19]
            r13 = baseAddr + 0x24E689C1;            //lea r13, [0x000000002236FC1E]
            rcx = r11 + r12 * 1;            //lea rcx, [r11+r12*1]
            rax ^= rcx;             //xor rax, rcx
            rdx = baseAddr + 0x3B21;                //lea rdx, [0xFFFFFFFFFD50A9E2]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B701A0]
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
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD5068A8]
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
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD506C40]
            rax ^= rcx;             //xor rax, rcx
            rcx = baseAddr + 0x5B0222F4;            //lea rcx, [0x0000000058528B47]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B6FC35]
            r15 = baseAddr + 0x852;                 //lea r15, [0xFFFFFFFFFD50707F]
            rcx = 0xF7D4FABCE6FC022;                //mov rcx, 0xF7D4FABCE6FC022
            rax += rcx;             //add rax, rcx
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rcx = ~rcx;             //not rcx
            rax *= driver::read<uint64_t>(rcx + 0x7);               //imul rax, [rcx+0x07]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD5065E6]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B6F875]
            r15 = baseAddr + 0x12585A59;            //lea r15, [0x000000000FA8BEC6]
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
            rax = baseAddr + 0x78217335;            //lea rax, [0x000000007571D5AC]
            rcx += r11;             //add rcx, r11
            rax += rcx;             //add rax, rcx
            rcx = 0xC20F4E2AD24BC517;               //mov rcx, 0xC20F4E2AD24BC517
            rax ^= rcx;             //xor rax, rcx
            return rax;
        }
        case 14:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B6F2F9]
            r15 = baseAddr + 0x3CF1;                //lea r15, [0xFFFFFFFFFD509BE2]
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
            rcx = baseAddr + 0x32FFEB8B;            //lea rcx, [0x0000000030504981]
            rcx = ~rcx;             //not rcx
            rcx *= r11;             //imul rcx, r11
            rax += rcx;             //add rax, rcx
            return rax;
        }
        case 15:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB6693F5);             //mov r10, [0x0000000008B6EDA6]
            r12 = baseAddr + 0x23AC2B6F;            //lea r12, [0x0000000020FC850D]
            rcx = baseAddr;                 //lea rcx, [0xFFFFFFFFFD505775]
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

    uintptr_t bnet_decrypt_bone_base(uint64_t baseAddr, uint64_t peb)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rdx = driver::read<uint64_t>(baseAddr + 0x117E5D18);
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
            r9 = driver::read<uint64_t>(baseAddr + 0xB6694C9);              //mov r9, [0x00000000072380B2]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCE922]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x0000000007237BF3]
            rax = 0x311E3C7DD1297B69;               //mov rax, 0x311E3C7DD1297B69
            rdx *= rax;             //imul rdx, rax
            rcx = r11;              //mov rcx, r11
            rcx = ~rcx;             //not rcx
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr + 0x437D3D7F;            //lea rax, [0x000000003F3A22FF]
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
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCE54A]
            rax += 0x3B261317;              //add rax, 0x3B261317
            rax += r11;             //add rax, r11
            rdx += rax;             //add rdx, rax
            rax = 0x85B82AEE944DCF96;               //mov rax, 0x85B82AEE944DCF96
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCE64F]
            rdx += rax;             //add rdx, rax
            return rdx;
        }
        case 2:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB6694C9);              //mov r9, [0x000000000723774E]
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
            r9 = driver::read<uint64_t>(baseAddr + 0xB6694C9);              //mov r9, [0x0000000007237312]
            r10 = baseAddr + 0x1314A155;            //lea r10, [0x000000000ED17F86]
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r9;              //xor rax, r9
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCDD53]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x000000000723701C]
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
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCD7B0]
            rax += 0x8F29;          //add rax, 0x8F29
            rax += r11;             //add rax, r11
            rdx ^= rax;             //xor rdx, rax
            rax = 0xD43375ADC5407E51;               //mov rax, 0xD43375ADC5407E51
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 5:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB6694C9);              //mov r9, [0x0000000007236B90]
            r12 = baseAddr + 0x12426297;            //lea r12, [0x000000000DFF393F]
            rax = 0x7C5DF0A12057BE6;                //mov rax, 0x7C5DF0A12057BE6
            rdx -= rax;             //sub rdx, rax
            rax = 0x83F8FC0408B5D1AB;               //mov rax, 0x83F8FC0408B5D1AB
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr + 0x158DE932;            //lea rax, [0x00000000114ABE51]
            rax = ~rax;             //not rax
            rax *= r11;             //imul rax, r11
            rdx += rax;             //add rdx, rax
            rax = r11;              //mov rax, r11
            rax *= r12;             //imul rax, r12
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCD468]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x0000000007236624]
            r12 = baseAddr + 0x6DA9DAD4;            //lea r12, [0x000000006966AC17]
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
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCCEE5]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x0000000007236244]
            r13 = baseAddr + 0x4354;                //lea r13, [0xFFFFFFFFFBBD10BC]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x0000000007235DBD]
            r12 = baseAddr + 0x7D814959;            //lea r12, [0x00000000793E123A]
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
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCC78F]
            rdx ^= rax;             //xor rdx, rax
            return rdx;
        }
        case 9:
        {
            r9 = driver::read<uint64_t>(baseAddr + 0xB6694C9);              //mov r9, [0x0000000007235A91]
            rax = rdx;              //mov rax, rdx
            rax >>= 0xB;            //shr rax, 0x0B
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x16;           //shr rax, 0x16
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x2C;           //shr rax, 0x2C
            rdx ^= rax;             //xor rdx, rax
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCC194]
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
            rax -= baseAddr;                //sub rax, [rbp-0x59] -- didn't find trace -> use base
            rdx += rax;             //add rdx, rax
            rax = 0x5E76F88978AFE528;               //mov rax, 0x5E76F88978AFE528
            rdx += rax;             //add rdx, rax
            rax = 0x33557C5CEFBE234B;               //mov rax, 0x33557C5CEFBE234B
            rdx *= rax;             //imul rdx, rax
            return rdx;
        }
        case 10:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x000000000723558D]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCBF5B]
            rdx -= rax;             //sub rdx, rax
            rcx = rdx;              //mov rcx, rdx
            rcx >>= 0x27;           //shr rcx, 0x27
            rcx ^= rdx;             //xor rcx, rdx
            rdx = baseAddr + 0x9688;                //lea rdx, [0xFFFFFFFFFBBD54DD]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x00000000072350D0]
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rax = baseAddr + 0x1E13DCA3;            //lea rax, [0x0000000019D094FA]
            rax = ~rax;             //not rax
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rax += r11;             //add rax, r11
            rcx ^= r10;             //xor rcx, r10
            rdx += rax;             //add rdx, rax
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx *= driver::read<uint64_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCB829]
            rax += 0x9D9E;          //add rax, 0x9D9E
            rax += r11;             //add rax, r11
            rdx += rax;             //add rdx, rax
            rax = r11;              //mov rax, r11
            rax -= baseAddr;                //sub rax, [rbp-0x59] -- didn't find trace -> use base
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
            rcx = baseAddr + 0x7C2A0085;            //lea rcx, [0x0000000077E6B96E]
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
            r9 = driver::read<uint64_t>(baseAddr + 0xB6694C9);              //mov r9, [0x0000000007234C92]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x0000000007234816]
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
            rcx = baseAddr + 0x7FFA;                //lea rcx, [0xFFFFFFFFFBBD32AF]
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
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCAF33]
            rax += 0x1CFB;          //add rax, 0x1CFB
            rax += r11;             //add rax, r11
            rdx += rax;             //add rdx, rax
            return rdx;
        }
        case 14:
        {
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x0000000007234297]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x1C;           //shr rax, 0x1C
            rdx ^= rax;             //xor rdx, rax
            rax = rdx;              //mov rax, rdx
            rax >>= 0x38;           //shr rax, 0x38
            rax ^= rdx;             //xor rax, rdx
            rdx = baseAddr;                 //lea rdx, [0xFFFFFFFFFBBCAA86]
            rax -= rdx;             //sub rax, rdx
            rdx = r11 + 0xffffffffd3bc8867;                 //lea rdx, [r11-0x2C437799]
            rdx += rax;             //add rdx, rax
            rax = 0;                //and rax, 0xFFFFFFFFC0000000
            rax = _rotl64(rax, 0x10);               //rol rax, 0x10
            rax ^= r10;             //xor rax, r10
            rax = _byteswap_uint64(rax);            //bswap rax
            rdx *= driver::read<uint64_t>(rax + 0x11);              //imul rdx, [rax+0x11]
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCA99B]
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
            r10 = driver::read<uint64_t>(baseAddr + 0xB6694C9);             //mov r10, [0x0000000007233E2E]
            rax = rdx;              //mov rax, rdx
            rax >>= 0x25;           //shr rax, 0x25
            rdx ^= rax;             //xor rdx, rax
            rdx -= r11;             //sub rdx, r11
            rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
            rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
            rcx ^= r10;             //xor rcx, r10
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCA704]
            rax += 0x953;           //add rax, 0x953
            rax += r11;             //add rax, r11
            rcx = _byteswap_uint64(rcx);            //bswap rcx
            rdx ^= rax;             //xor rdx, rax
            rdx *= driver::read<uint64_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
            rax = 0xEDC186E4F45D82CF;               //mov rax, 0xEDC186E4F45D82CF
            rdx *= rax;             //imul rdx, rax
            rdx -= r11;             //sub rdx, r11
            rax = baseAddr;                 //lea rax, [0xFFFFFFFFFBBCA60E]
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

    uintptr_t bnet_get_bone_index(uint32_t bone_index, uint64_t baseAddr)
    {
        const uint64_t mb = baseAddr;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
        rbx = bone_index;
        rcx = rbx * 0x13C8;
        rax = 0xD8CE01BF28E39A45;               //mov rax, 0xD8CE01BF28E39A45
        rbx = baseAddr;                 //lea rbx, [0xFFFFFFFFFD4B295E]
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
        rax = driver::read<uint16_t>(rcx + rbx * 1 + 0xA6D8900);                //movzx eax, word ptr [rcx+rbx*1+0xA6D8900]
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
        rsi = driver::read<uint16_t>(rcx + rbx * 1 + 0xA6E7530);                //movsx esi, word ptr [rcx+rbx*1+0xA6E7530]
        return rsi;
    }
}