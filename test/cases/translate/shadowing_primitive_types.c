unsigned anyerror = 2;
#define noreturn _Noreturn
typedef enum {
    f32,
    u32,
} BadEnum;
int panic(void) {
    return 0;
}

// translate
//
// pub export var @"anyerror": c_uint = 2;
//
// pub const @"noreturn" = @compileError("unable to translate C expr: unexpected token '_Noreturn'");
//
// pub const @"f32": c_int = 0;
// pub const @"u32": c_int = 1;
//
// export fn panic() c_int {
//     return 0;
// }
