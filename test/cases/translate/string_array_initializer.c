static const char foo[] = {"bar"};

// translate
//
// pub const foo: [4]c_char = @as(*const [4]c_char, @ptrCast("bar")).*;
