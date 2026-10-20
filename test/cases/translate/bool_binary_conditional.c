int foo(void) {
    int x = 1;
    int y = 1;
    int z = 3;

    int temp3 = (x && y) ?: z;
    if ((x && y) ?: z)
      ;
    _Bool temp4 = (x && y) ?: z;

    return temp3;
}

// translate
//
// pub export fn foo() c_int {
//     var x: c_int = 1;
//     _ = &x;
//     var y: c_int = 1;
//     _ = &y;
//     var z: c_int = 3;
//     _ = &z;
//     var temp3: c_int = blk: {
//         const cond_temp = @intFromBool((x != 0) and (y != 0));
//         break :blk if (cond_temp != 0) cond_temp else z;
//     };
//     _ = &temp3;
//     if (blk: {
//         const cond_temp = (x != 0) and (y != 0);
//         break :blk if (cond_temp) cond_temp else z != 0;
//     }) {}
//     var temp4: bool = blk: {
//         const cond_temp = (x != 0) and (y != 0);
//         break :blk if (cond_temp) cond_temp else z != 0;
//     };
//     _ = &temp4;
//     return temp3;
// }
