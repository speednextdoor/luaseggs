// hi
// file name: seggs.c
// author: speedsterkawaii
// last modified: 2/25/2025 9:03 AM

// this is mostly found in lapi.cpp's lua_gettop 
// you can disassemble by going through roblox and searching for "Argument 3 missing or nil" as gettop gets used there a lot
// anything that accepts arguments and has a proper handler or "check" for the arguments always have gettop

__int64 topoffset = 16;
__int64 baseoffset = 8;

void r_lua_pushnil(uint64_t a1) {
    uint64_t top = *reinterpret_cast<uint64_t*>(a1 + topoffset); // luastate ptr + top
    *reinterpret_cast<uint64_t*>(top + 12) = 0; // push nil
     *reinterpret_cast<uint64_t*>(a1 + topoffset) += 16; // increment top
}

int r_lua_gettop(uintptr_t a1) { // is this even hard...anyone should be able to do this
    return (int)((*(uintptr_t*)(a1 + topoffset) - *(uintptr_t*)(a1 + baseoffset)) >> 4); // DEXTER MOGGIN...
}

