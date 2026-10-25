void foo(void) {
    int len;
    while (--len);
    while ((int){0});
    int a __attribute__((vector_size(64)));
    while (a[len] = 0);
}

// translate
//
// pub export fn foo() void {
//     var len: c_int = undefined;
//     _ = &len;
//     while (blk: {
//         const ref = &len;
//         ref.* -= 1;
//         break :blk ref.* != 0;
//     }) {}
//     while (@as(c_int, 0) != 0) {}
//     var a: @Vector(16, c_int) = undefined;
//     _ = &a;
//     while (blk: {
//         const tmp_base = &a;
//         const tmp_index = len;
//         const new = @as(c_int, 0);
//         __helpers.vectorIndexStore(tmp_base, tmp_index, new);
//         break :blk new != 0;
//     }) {}
// }
