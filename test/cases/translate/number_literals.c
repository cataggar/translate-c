float a = 1.20'000f;
float b = 000.123'456789f;
int c = 00'0000002;

#define f 000.1234567'89f

#define i 00000000'2

// translate
// args = -std=c23
//
// pub export var a: f32 = 1.20_000;
// pub export var b: f32 = 0.123_456789;
// pub export var c: c_int = 0o0_0000002;
//
// pub const f = @as(f32, 0.1234567_89);
//
// pub const i = @as(c_int, 0o0000000_2);
