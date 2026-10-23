extern int printf(const char *restrict, ...);

#define PRINT_INT(a) printf("%d\n", a)

#define __DARWIN_FD_ZERO1(p)     __builtin_bzero(p, sizeof(*(p)))
#define __DARWIN_FD_ZERO2(p)     bzero(p, sizeof(*(p)))
#define FD_ZERO1(p)      __DARWIN_FD_ZERO1(p)
#define FD_ZERO2(p)      __DARWIN_FD_ZERO2(p)

// translate
//
// pub extern fn printf(noalias [*c]const c_char, ...) c_int;
//
// pub inline fn PRINT_INT(a: anytype) @TypeOf(printf("%d\n", a)) {
//     _ = &a;
//     return printf("%d\n", a);
// }
//
// pub inline fn __DARWIN_FD_ZERO1(p: anytype) @TypeOf(__builtin.c.bzero(p, __helpers.sizeof(p.*))) {
//     _ = &p;
//     return __builtin.c.bzero(p, __helpers.sizeof(p.*));
// }
//
// pub inline fn __DARWIN_FD_ZERO2(p: anytype) @TypeOf(__builtin.c.bzero(p, __helpers.sizeof(p.*))) {
//     _ = &p;
//     return __builtin.c.bzero(p, __helpers.sizeof(p.*));
// }
//
// pub inline fn FD_ZERO1(p: anytype) @TypeOf(__DARWIN_FD_ZERO1(p)) {
//     _ = &p;
//     return __DARWIN_FD_ZERO1(p);
// }
//
// pub inline fn FD_ZERO2(p: anytype) @TypeOf(__DARWIN_FD_ZERO2(p)) {
//     _ = &p;
//     return __DARWIN_FD_ZERO2(p);
// }
