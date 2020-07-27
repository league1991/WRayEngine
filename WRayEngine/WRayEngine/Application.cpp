#include "Application.h"





Application::~Application() {  }


static const uint32_t __draw_cube_vert[287] = {
    0x07230203, 0x00010000, 0x00080008, 0x00000020,
    0x00000000, 0x00020011, 0x00000001, 0x0006000b,
    0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e,
    0x00000000, 0x0003000e, 0x00000000, 0x00000001,
    0x0009000f, 0x00000000, 0x00000004, 0x6e69616d,
    0x00000000, 0x00000009, 0x0000000b, 0x00000012,
    0x0000001c, 0x00030003, 0x00000002, 0x00000190,
    0x00090004, 0x415f4c47, 0x735f4252, 0x72617065,
    0x5f657461, 0x64616873, 0x6f5f7265, 0x63656a62,
    0x00007374, 0x00090004, 0x415f4c47, 0x735f4252,
    0x69646168, 0x6c5f676e, 0x75676e61, 0x5f656761,
    0x70303234, 0x006b6361, 0x00040005, 0x00000004,
    0x6e69616d, 0x00000000, 0x00050005, 0x00000009,
    0x4374756f, 0x726f6c6f, 0x00000000, 0x00040005,
    0x0000000b, 0x6f436e69, 0x00726f6c, 0x00060005,
    0x00000010, 0x505f6c67, 0x65567265, 0x78657472,
    0x00000000, 0x00060006, 0x00000010, 0x00000000,
    0x505f6c67, 0x7469736f, 0x006e6f69, 0x00070006,
    0x00000010, 0x00000001, 0x505f6c67, 0x746e696f,
    0x657a6953, 0x00000000, 0x00070006, 0x00000010,
    0x00000002, 0x435f6c67, 0x4470696c, 0x61747369,
    0x0065636e, 0x00030005, 0x00000012, 0x00000000,
    0x00050005, 0x00000016, 0x66667562, 0x61567265,
    0x0000736c, 0x00040006, 0x00000016, 0x00000000,
    0x0070766d, 0x00060005, 0x00000018, 0x7542796d,
    0x72656666, 0x736c6156, 0x00000000, 0x00030005,
    0x0000001c, 0x00736f70, 0x00040047, 0x00000009,
    0x0000001e, 0x00000000, 0x00040047, 0x0000000b,
    0x0000001e, 0x00000001, 0x00050048, 0x00000010,
    0x00000000, 0x0000000b, 0x00000000, 0x00050048,
    0x00000010, 0x00000001, 0x0000000b, 0x00000001,
    0x00050048, 0x00000010, 0x00000002, 0x0000000b,
    0x00000003, 0x00030047, 0x00000010, 0x00000002,
    0x00040048, 0x00000016, 0x00000000, 0x00000005,
    0x00050048, 0x00000016, 0x00000000, 0x00000023,
    0x00000000, 0x00050048, 0x00000016, 0x00000000,
    0x00000007, 0x00000010, 0x00030047, 0x00000016,
    0x00000002, 0x00040047, 0x00000018, 0x00000022,
    0x00000000, 0x00040047, 0x00000018, 0x00000021,
    0x00000000, 0x00040047, 0x0000001c, 0x0000001e,
    0x00000000, 0x00020013, 0x00000002, 0x00030021,
    0x00000003, 0x00000002, 0x00030016, 0x00000006,
    0x00000020, 0x00040017, 0x00000007, 0x00000006,
    0x00000004, 0x00040020, 0x00000008, 0x00000003,
    0x00000007, 0x0004003b, 0x00000008, 0x00000009,
    0x00000003, 0x00040020, 0x0000000a, 0x00000001,
    0x00000007, 0x0004003b, 0x0000000a, 0x0000000b,
    0x00000001, 0x00040015, 0x0000000d, 0x00000020,
    0x00000000, 0x0004002b, 0x0000000d, 0x0000000e,
    0x00000001, 0x0004001c, 0x0000000f, 0x00000006,
    0x0000000e, 0x0005001e, 0x00000010, 0x00000007,
    0x00000006, 0x0000000f, 0x00040020, 0x00000011,
    0x00000003, 0x00000010, 0x0004003b, 0x00000011,
    0x00000012, 0x00000003, 0x00040015, 0x00000013,
    0x00000020, 0x00000001, 0x0004002b, 0x00000013,
    0x00000014, 0x00000000, 0x00040018, 0x00000015,
    0x00000007, 0x00000004, 0x0003001e, 0x00000016,
    0x00000015, 0x00040020, 0x00000017, 0x00000002,
    0x00000016, 0x0004003b, 0x00000017, 0x00000018,
    0x00000002, 0x00040020, 0x00000019, 0x00000002,
    0x00000015, 0x0004003b, 0x0000000a, 0x0000001c,
    0x00000001, 0x00050036, 0x00000002, 0x00000004,
    0x00000000, 0x00000003, 0x000200f8, 0x00000005,
    0x0004003d, 0x00000007, 0x0000000c, 0x0000000b,
    0x0003003e, 0x00000009, 0x0000000c, 0x00050041,
    0x00000019, 0x0000001a, 0x00000018, 0x00000014,
    0x0004003d, 0x00000015, 0x0000001b, 0x0000001a,
    0x0004003d, 0x00000007, 0x0000001d, 0x0000001c,
    0x00050091, 0x00000007, 0x0000001e, 0x0000001b,
    0x0000001d, 0x00050041, 0x00000008, 0x0000001f,
    0x00000012, 0x00000014, 0x0003003e, 0x0000001f,
    0x0000001e, 0x000100fd, 0x00010038,
};


static const uint32_t __draw_cube_frag[112] = {
    0x07230203, 0x00010000, 0x00080008, 0x0000000d,
    0x00000000, 0x00020011, 0x00000001, 0x0006000b,
    0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e,
    0x00000000, 0x0003000e, 0x00000000, 0x00000001,
    0x0007000f, 0x00000004, 0x00000004, 0x6e69616d,
    0x00000000, 0x00000009, 0x0000000b, 0x00030010,
    0x00000004, 0x00000007, 0x00030003, 0x00000002,
    0x00000190, 0x00090004, 0x415f4c47, 0x735f4252,
    0x72617065, 0x5f657461, 0x64616873, 0x6f5f7265,
    0x63656a62, 0x00007374, 0x00090004, 0x415f4c47,
    0x735f4252, 0x69646168, 0x6c5f676e, 0x75676e61,
    0x5f656761, 0x70303234, 0x006b6361, 0x00040005,
    0x00000004, 0x6e69616d, 0x00000000, 0x00050005,
    0x00000009, 0x4374756f, 0x726f6c6f, 0x00000000,
    0x00040005, 0x0000000b, 0x6f6c6f63, 0x00000072,
    0x00040047, 0x00000009, 0x0000001e, 0x00000000,
    0x00040047, 0x0000000b, 0x0000001e, 0x00000000,
    0x00020013, 0x00000002, 0x00030021, 0x00000003,
    0x00000002, 0x00030016, 0x00000006, 0x00000020,
    0x00040017, 0x00000007, 0x00000006, 0x00000004,
    0x00040020, 0x00000008, 0x00000003, 0x00000007,
    0x0004003b, 0x00000008, 0x00000009, 0x00000003,
    0x00040020, 0x0000000a, 0x00000001, 0x00000007,
    0x0004003b, 0x0000000a, 0x0000000b, 0x00000001,
    0x00050036, 0x00000002, 0x00000004, 0x00000000,
    0x00000003, 0x000200f8, 0x00000005, 0x0004003d,
    0x00000007, 0x0000000c, 0x0000000b, 0x0003003e,
    0x00000009, 0x0000000c, 0x000100fd, 0x00010038,
};


static const uint32_t template_vert[296] = {
    0x07230203, 0x00010000, 0x00080008, 0x00000023,
    0x00000000, 0x00020011, 0x00000001, 0x0006000b,
    0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e,
    0x00000000, 0x0003000e, 0x00000000, 0x00000001,
    0x0009000f, 0x00000000, 0x00000004, 0x6e69616d,
    0x00000000, 0x00000009, 0x0000000b, 0x00000013,
    0x0000001e, 0x00030003, 0x00000002, 0x00000190,
    0x00090004, 0x415f4c47, 0x735f4252, 0x72617065,
    0x5f657461, 0x64616873, 0x6f5f7265, 0x63656a62,
    0x00007374, 0x00090004, 0x415f4c47, 0x735f4252,
    0x69646168, 0x6c5f676e, 0x75676e61, 0x5f656761,
    0x70303234, 0x006b6361, 0x00040005, 0x00000004,
    0x6e69616d, 0x00000000, 0x00050005, 0x00000009,
    0x63786574, 0x64726f6f, 0x00000000, 0x00050005,
    0x0000000b, 0x65546e69, 0x6f6f4378, 0x00736472,
    0x00060005, 0x00000011, 0x505f6c67, 0x65567265,
    0x78657472, 0x00000000, 0x00060006, 0x00000011,
    0x00000000, 0x505f6c67, 0x7469736f, 0x006e6f69,
    0x00070006, 0x00000011, 0x00000001, 0x505f6c67,
    0x746e696f, 0x657a6953, 0x00000000, 0x00070006,
    0x00000011, 0x00000002, 0x435f6c67, 0x4470696c,
    0x61747369, 0x0065636e, 0x00030005, 0x00000013,
    0x00000000, 0x00030005, 0x00000017, 0x00667562,
    0x00040006, 0x00000017, 0x00000000, 0x0070766d,
    0x00040005, 0x00000019, 0x66756275, 0x00000000,
    0x00030005, 0x0000001e, 0x00736f70, 0x00040047,
    0x00000009, 0x0000001e, 0x00000000, 0x00040047,
    0x0000000b, 0x0000001e, 0x00000001, 0x00050048,
    0x00000011, 0x00000000, 0x0000000b, 0x00000000,
    0x00050048, 0x00000011, 0x00000001, 0x0000000b,
    0x00000001, 0x00050048, 0x00000011, 0x00000002,
    0x0000000b, 0x00000003, 0x00030047, 0x00000011,
    0x00000002, 0x00040048, 0x00000017, 0x00000000,
    0x00000005, 0x00050048, 0x00000017, 0x00000000,
    0x00000023, 0x00000000, 0x00050048, 0x00000017,
    0x00000000, 0x00000007, 0x00000010, 0x00030047,
    0x00000017, 0x00000002, 0x00040047, 0x00000019,
    0x00000022, 0x00000000, 0x00040047, 0x00000019,
    0x00000021, 0x00000000, 0x00040047, 0x0000001e,
    0x0000001e, 0x00000000, 0x00020013, 0x00000002,
    0x00030021, 0x00000003, 0x00000002, 0x00030016,
    0x00000006, 0x00000020, 0x00040017, 0x00000007,
    0x00000006, 0x00000002, 0x00040020, 0x00000008,
    0x00000003, 0x00000007, 0x0004003b, 0x00000008,
    0x00000009, 0x00000003, 0x00040020, 0x0000000a,
    0x00000001, 0x00000007, 0x0004003b, 0x0000000a,
    0x0000000b, 0x00000001, 0x00040017, 0x0000000d,
    0x00000006, 0x00000004, 0x00040015, 0x0000000e,
    0x00000020, 0x00000000, 0x0004002b, 0x0000000e,
    0x0000000f, 0x00000001, 0x0004001c, 0x00000010,
    0x00000006, 0x0000000f, 0x0005001e, 0x00000011,
    0x0000000d, 0x00000006, 0x00000010, 0x00040020,
    0x00000012, 0x00000003, 0x00000011, 0x0004003b,
    0x00000012, 0x00000013, 0x00000003, 0x00040015,
    0x00000014, 0x00000020, 0x00000001, 0x0004002b,
    0x00000014, 0x00000015, 0x00000000, 0x00040018,
    0x00000016, 0x0000000d, 0x00000004, 0x0003001e,
    0x00000017, 0x00000016, 0x00040020, 0x00000018,
    0x00000002, 0x00000017, 0x0004003b, 0x00000018,
    0x00000019, 0x00000002, 0x00040020, 0x0000001a,
    0x00000002, 0x00000016, 0x00040020, 0x0000001d,
    0x00000001, 0x0000000d, 0x0004003b, 0x0000001d,
    0x0000001e, 0x00000001, 0x00040020, 0x00000021,
    0x00000003, 0x0000000d, 0x00050036, 0x00000002,
    0x00000004, 0x00000000, 0x00000003, 0x000200f8,
    0x00000005, 0x0004003d, 0x00000007, 0x0000000c,
    0x0000000b, 0x0003003e, 0x00000009, 0x0000000c,
    0x00050041, 0x0000001a, 0x0000001b, 0x00000019,
    0x00000015, 0x0004003d, 0x00000016, 0x0000001c,
    0x0000001b, 0x0004003d, 0x0000000d, 0x0000001f,
    0x0000001e, 0x00050091, 0x0000000d, 0x00000020,
    0x0000001c, 0x0000001f, 0x00050041, 0x00000021,
    0x00000022, 0x00000013, 0x00000015, 0x0003003e,
    0x00000022, 0x00000020, 0x000100fd, 0x00010038,
};


static const uint32_t template_frag[163] = {
    0x07230203, 0x00010000, 0x00080008, 0x00000015,
    0x00000000, 0x00020011, 0x00000001, 0x0006000b,
    0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e,
    0x00000000, 0x0003000e, 0x00000000, 0x00000001,
    0x0007000f, 0x00000004, 0x00000004, 0x6e69616d,
    0x00000000, 0x00000009, 0x00000011, 0x00030010,
    0x00000004, 0x00000007, 0x00030003, 0x00000002,
    0x00000190, 0x00090004, 0x415f4c47, 0x735f4252,
    0x72617065, 0x5f657461, 0x64616873, 0x6f5f7265,
    0x63656a62, 0x00007374, 0x00090004, 0x415f4c47,
    0x735f4252, 0x69646168, 0x6c5f676e, 0x75676e61,
    0x5f656761, 0x70303234, 0x006b6361, 0x00040005,
    0x00000004, 0x6e69616d, 0x00000000, 0x00050005,
    0x00000009, 0x4374756f, 0x726f6c6f, 0x00000000,
    0x00030005, 0x0000000d, 0x00786574, 0x00050005,
    0x00000011, 0x63786574, 0x64726f6f, 0x00000000,
    0x00040047, 0x00000009, 0x0000001e, 0x00000000,
    0x00040047, 0x0000000d, 0x00000022, 0x00000000,
    0x00040047, 0x0000000d, 0x00000021, 0x00000001,
    0x00040047, 0x00000011, 0x0000001e, 0x00000000,
    0x00020013, 0x00000002, 0x00030021, 0x00000003,
    0x00000002, 0x00030016, 0x00000006, 0x00000020,
    0x00040017, 0x00000007, 0x00000006, 0x00000004,
    0x00040020, 0x00000008, 0x00000003, 0x00000007,
    0x0004003b, 0x00000008, 0x00000009, 0x00000003,
    0x00090019, 0x0000000a, 0x00000006, 0x00000001,
    0x00000000, 0x00000000, 0x00000000, 0x00000001,
    0x00000000, 0x0003001b, 0x0000000b, 0x0000000a,
    0x00040020, 0x0000000c, 0x00000000, 0x0000000b,
    0x0004003b, 0x0000000c, 0x0000000d, 0x00000000,
    0x00040017, 0x0000000f, 0x00000006, 0x00000002,
    0x00040020, 0x00000010, 0x00000001, 0x0000000f,
    0x0004003b, 0x00000010, 0x00000011, 0x00000001,
    0x0004002b, 0x00000006, 0x00000013, 0x00000000,
    0x00050036, 0x00000002, 0x00000004, 0x00000000,
    0x00000003, 0x000200f8, 0x00000005, 0x0004003d,
    0x0000000b, 0x0000000e, 0x0000000d, 0x0004003d,
    0x0000000f, 0x00000012, 0x00000011, 0x00070058,
    0x00000007, 0x00000014, 0x0000000e, 0x00000012,
    0x00000002, 0x00000013, 0x0003003e, 0x00000009,
    0x00000014, 0x000100fd, 0x00010038,
};

struct Vertex {
    float posX, posY, posZ, posW;  // Position data
    float r, g, b, a;              // Color
};

struct VertexUV {
    float posX, posY, posZ, posW;  // Position data
    float u, v;                    // texture u,v
};

#define XYZ1(_x_, _y_, _z_) (_x_), (_y_), (_z_), 1.f
#define UV(_u_, _v_) (_u_), (_v_)

static const Vertex g_vbData[] = {
    {XYZ1(-1, -1, -1), XYZ1(0.f, 0.f, 0.f)}, {XYZ1(1, -1, -1), XYZ1(1.f, 0.f, 0.f)}, {XYZ1(-1, 1, -1), XYZ1(0.f, 1.f, 0.f)},
    {XYZ1(-1, 1, -1), XYZ1(0.f, 1.f, 0.f)},  {XYZ1(1, -1, -1), XYZ1(1.f, 0.f, 0.f)}, {XYZ1(1, 1, -1), XYZ1(1.f, 1.f, 0.f)},

    {XYZ1(-1, -1, 1), XYZ1(0.f, 0.f, 1.f)},  {XYZ1(-1, 1, 1), XYZ1(0.f, 1.f, 1.f)},  {XYZ1(1, -1, 1), XYZ1(1.f, 0.f, 1.f)},
    {XYZ1(1, -1, 1), XYZ1(1.f, 0.f, 1.f)},   {XYZ1(-1, 1, 1), XYZ1(0.f, 1.f, 1.f)},  {XYZ1(1, 1, 1), XYZ1(1.f, 1.f, 1.f)},

    {XYZ1(1, 1, 1), XYZ1(1.f, 1.f, 1.f)},    {XYZ1(1, 1, -1), XYZ1(1.f, 1.f, 0.f)},  {XYZ1(1, -1, 1), XYZ1(1.f, 0.f, 1.f)},
    {XYZ1(1, -1, 1), XYZ1(1.f, 0.f, 1.f)},   {XYZ1(1, 1, -1), XYZ1(1.f, 1.f, 0.f)},  {XYZ1(1, -1, -1), XYZ1(1.f, 0.f, 0.f)},

    {XYZ1(-1, 1, 1), XYZ1(0.f, 1.f, 1.f)},   {XYZ1(-1, -1, 1), XYZ1(0.f, 0.f, 1.f)}, {XYZ1(-1, 1, -1), XYZ1(0.f, 1.f, 0.f)},
    {XYZ1(-1, 1, -1), XYZ1(0.f, 1.f, 0.f)},  {XYZ1(-1, -1, 1), XYZ1(0.f, 0.f, 1.f)}, {XYZ1(-1, -1, -1), XYZ1(0.f, 0.f, 0.f)},

    {XYZ1(1, 1, 1), XYZ1(1.f, 1.f, 1.f)},    {XYZ1(-1, 1, 1), XYZ1(0.f, 1.f, 1.f)},  {XYZ1(1, 1, -1), XYZ1(1.f, 1.f, 0.f)},
    {XYZ1(1, 1, -1), XYZ1(1.f, 1.f, 0.f)},   {XYZ1(-1, 1, 1), XYZ1(0.f, 1.f, 1.f)},  {XYZ1(-1, 1, -1), XYZ1(0.f, 1.f, 0.f)},

    {XYZ1(1, -1, 1), XYZ1(1.f, 0.f, 1.f)},   {XYZ1(1, -1, -1), XYZ1(1.f, 0.f, 0.f)}, {XYZ1(-1, -1, 1), XYZ1(0.f, 0.f, 1.f)},
    {XYZ1(-1, -1, 1), XYZ1(0.f, 0.f, 1.f)},  {XYZ1(1, -1, -1), XYZ1(1.f, 0.f, 0.f)}, {XYZ1(-1, -1, -1), XYZ1(0.f, 0.f, 0.f)},
};

static const Vertex g_vb_solid_face_colors_Data[] = {
    // red face
    {XYZ1(-1, -1, 1), XYZ1(1.f, 0.f, 0.f)},
    {XYZ1(-1, 1, 1), XYZ1(1.f, 0.f, 0.f)},
    {XYZ1(1, -1, 1), XYZ1(1.f, 0.f, 0.f)},
    {XYZ1(1, -1, 1), XYZ1(1.f, 0.f, 0.f)},
    {XYZ1(-1, 1, 1), XYZ1(1.f, 0.f, 0.f)},
    {XYZ1(1, 1, 1), XYZ1(1.f, 0.f, 0.f)},
    // green face
    {XYZ1(-1, -1, -1), XYZ1(0.f, 1.f, 0.f)},
    {XYZ1(1, -1, -1), XYZ1(0.f, 1.f, 0.f)},
    {XYZ1(-1, 1, -1), XYZ1(0.f, 1.f, 0.f)},
    {XYZ1(-1, 1, -1), XYZ1(0.f, 1.f, 0.f)},
    {XYZ1(1, -1, -1), XYZ1(0.f, 1.f, 0.f)},
    {XYZ1(1, 1, -1), XYZ1(0.f, 1.f, 0.f)},
    // blue face
    {XYZ1(-1, 1, 1), XYZ1(0.f, 0.f, 1.f)},
    {XYZ1(-1, -1, 1), XYZ1(0.f, 0.f, 1.f)},
    {XYZ1(-1, 1, -1), XYZ1(0.f, 0.f, 1.f)},
    {XYZ1(-1, 1, -1), XYZ1(0.f, 0.f, 1.f)},
    {XYZ1(-1, -1, 1), XYZ1(0.f, 0.f, 1.f)},
    {XYZ1(-1, -1, -1), XYZ1(0.f, 0.f, 1.f)},
    // yellow face
    {XYZ1(1, 1, 1), XYZ1(1.f, 1.f, 0.f)},
    {XYZ1(1, 1, -1), XYZ1(1.f, 1.f, 0.f)},
    {XYZ1(1, -1, 1), XYZ1(1.f, 1.f, 0.f)},
    {XYZ1(1, -1, 1), XYZ1(1.f, 1.f, 0.f)},
    {XYZ1(1, 1, -1), XYZ1(1.f, 1.f, 0.f)},
    {XYZ1(1, -1, -1), XYZ1(1.f, 1.f, 0.f)},
    // magenta face
    {XYZ1(1, 1, 1), XYZ1(1.f, 0.f, 1.f)},
    {XYZ1(-1, 1, 1), XYZ1(1.f, 0.f, 1.f)},
    {XYZ1(1, 1, -1), XYZ1(1.f, 0.f, 1.f)},
    {XYZ1(1, 1, -1), XYZ1(1.f, 0.f, 1.f)},
    {XYZ1(-1, 1, 1), XYZ1(1.f, 0.f, 1.f)},
    {XYZ1(-1, 1, -1), XYZ1(1.f, 0.f, 1.f)},
    // cyan face
    {XYZ1(1, -1, 1), XYZ1(0.f, 1.f, 1.f)},
    {XYZ1(1, -1, -1), XYZ1(0.f, 1.f, 1.f)},
    {XYZ1(-1, -1, 1), XYZ1(0.f, 1.f, 1.f)},
    {XYZ1(-1, -1, 1), XYZ1(0.f, 1.f, 1.f)},
    {XYZ1(1, -1, -1), XYZ1(0.f, 1.f, 1.f)},
    {XYZ1(-1, -1, -1), XYZ1(0.f, 1.f, 1.f)},
};

static const VertexUV g_vb_texture_Data[] = {
    // left face
    {XYZ1(-1, -1, -1), UV(1.f, 0.f)},  // lft-top-front
    {XYZ1(-1, 1, 1), UV(0.f, 1.f)},    // lft-btm-back
    {XYZ1(-1, -1, 1), UV(0.f, 0.f)},   // lft-top-back
    {XYZ1(-1, 1, 1), UV(0.f, 1.f)},    // lft-btm-back
    {XYZ1(-1, -1, -1), UV(1.f, 0.f)},  // lft-top-front
    {XYZ1(-1, 1, -1), UV(1.f, 1.f)},   // lft-btm-front
    // front face
    {XYZ1(-1, -1, -1), UV(0.f, 0.f)},  // lft-top-front
    {XYZ1(1, -1, -1), UV(1.f, 0.f)},   // rgt-top-front
    {XYZ1(1, 1, -1), UV(1.f, 1.f)},    // rgt-btm-front
    {XYZ1(-1, -1, -1), UV(0.f, 0.f)},  // lft-top-front
    {XYZ1(1, 1, -1), UV(1.f, 1.f)},    // rgt-btm-front
    {XYZ1(-1, 1, -1), UV(0.f, 1.f)},   // lft-btm-front
    // top face
    {XYZ1(-1, -1, -1), UV(0.f, 1.f)},  // lft-top-front
    {XYZ1(1, -1, 1), UV(1.f, 0.f)},    // rgt-top-back
    {XYZ1(1, -1, -1), UV(1.f, 1.f)},   // rgt-top-front
    {XYZ1(-1, -1, -1), UV(0.f, 1.f)},  // lft-top-front
    {XYZ1(-1, -1, 1), UV(0.f, 0.f)},   // lft-top-back
    {XYZ1(1, -1, 1), UV(1.f, 0.f)},    // rgt-top-back
    // bottom face
    {XYZ1(-1, 1, -1), UV(0.f, 0.f)},  // lft-btm-front
    {XYZ1(1, 1, 1), UV(1.f, 1.f)},    // rgt-btm-back
    {XYZ1(-1, 1, 1), UV(0.f, 1.f)},   // lft-btm-back
    {XYZ1(-1, 1, -1), UV(0.f, 0.f)},  // lft-btm-front
    {XYZ1(1, 1, -1), UV(1.f, 0.f)},   // rgt-btm-front
    {XYZ1(1, 1, 1), UV(1.f, 1.f)},    // rgt-btm-back
    // right face
    {XYZ1(1, 1, -1), UV(0.f, 1.f)},   // rgt-btm-front
    {XYZ1(1, -1, 1), UV(1.f, 0.f)},   // rgt-top-back
    {XYZ1(1, 1, 1), UV(1.f, 1.f)},    // rgt-btm-back
    {XYZ1(1, -1, 1), UV(1.f, 0.f)},   // rgt-top-back
    {XYZ1(1, 1, -1), UV(0.f, 1.f)},   // rgt-btm-front
    {XYZ1(1, -1, -1), UV(0.f, 0.f)},  // rgt-top-front
    // back face
    {XYZ1(-1, 1, 1), UV(1.f, 1.f)},   // lft-btm-back
    {XYZ1(1, 1, 1), UV(0.f, 1.f)},    // rgt-btm-back
    {XYZ1(-1, -1, 1), UV(1.f, 0.f)},  // lft-top-back
    {XYZ1(-1, -1, 1), UV(1.f, 0.f)},  // lft-top-back
    {XYZ1(1, 1, 1), UV(0.f, 1.f)},    // rgt-btm-back
    {XYZ1(1, -1, 1), UV(0.f, 0.f)},   // rgt-top-back
};



static const char *vertShaderText =
"#version 400\n"
"#extension GL_ARB_separate_shader_objects : enable\n"
"#extension GL_ARB_shading_language_420pack : enable\n"
"layout (std140, binding = 0) uniform buf {"
"    mat4 mvp;"
"} ubuf;"
"layout (location = 0) in vec4 pos;"
"layout (location = 1) in vec2 inTexCoords;"
"layout (location = 0) out vec2 texcoord;"
"void main() {"
"   texcoord = inTexCoords;"
"   gl_Position = ubuf.mvp * pos;"
"}"
//
//"#version 400\n"
//"#extension GL_ARB_separate_shader_objects : enable\n"
//"#extension GL_ARB_shading_language_420pack : enable\n"
//"layout (std140, binding = 0) uniform bufferVals {\n"
//"    mat4 mvp;\n"
//"} myBufferVals;\n"
//"layout (location = 0) in vec4 pos;\n"
//"layout (location = 1) in vec4 inColor;\n"
//"layout (location = 0) out vec4 outColor;\n"
//"void main() {\n"
//"   outColor = inColor;\n"
//"   gl_Position = myBufferVals.mvp * pos;\n"
//"}\n"
;

static const char *fragShaderText =
"#version 400\n"
"#extension GL_ARB_separate_shader_objects : enable\n"
"#extension GL_ARB_shading_language_420pack : enable\n"
"layout (binding = 1) uniform sampler2D tex;"
"layout (location = 0) in vec2 texcoord;"
"layout (location = 0) out vec4 outColor;"
"void main() {"
"   outColor = textureLod(tex, texcoord, 0.0);"
"}"
//"#version 400\n"
//"#extension GL_ARB_separate_shader_objects : enable\n"
//"#extension GL_ARB_shading_language_420pack : enable\n"
//"layout (location = 0) in vec4 color;\n"
//"layout (location = 0) out vec4 outColor;\n"
//"void main() {\n"
//"   outColor = color;\n"
//"}\n"
;

void Application::initialize()
{
    VkResult U_ASSERT_ONLY res;
    char sample_title[] = "Draw Cube";
    const bool depthPresent = true;

    //process_command_line_args(info, argc, argv);
    init_global_layer_properties(info);
    init_instance_extension_names(info);
    init_device_extension_names(info);
    init_instance(info, sample_title);
    init_enumerate_device(info);
    init_window_size(info, 500, 500);
    init_connection(info);
    init_window(info);
    init_swapchain_extension(info);
    init_device(info);
    //init_command_pool(info);
    //init_command_buffer(info);
    //execute_begin_command_buffer(info);
    init_device_queue(info);
    init_swap_chain(info);

    info.per_frame.resize(info.swapchainImageCount);
    for (int i = 0; i < info.swapchainImageCount; i++)
    {
        init_per_frame(info, info.per_frame[i]);
    }

    init_depth_buffer(info);
    init_texture(info);
    init_uniform_buffer(info);
    init_descriptor_and_pipeline_layouts(info, true);
    init_renderpass(info, depthPresent);
    VkShaderModuleCreateInfo vert_info = {};
    VkShaderModuleCreateInfo frag_info = {};
    vert_info.sType = frag_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    vert_info.codeSize = sizeof(template_vert);
    vert_info.pCode = template_vert;
    frag_info.codeSize = sizeof(template_frag);
    frag_info.pCode = template_frag;
    //init_shaders(info, &vert_info, &frag_info);
    //init_shaders(info, vertShaderText, fragShaderText);

    vertexShader.init(info.device, Shader::Type::SHADER_VERTEX, "E:/Code/WRayEngine/WRayEngine/WRayEngine/test.vert", "main");
    fragmentShader.init(info.device, Shader::Type::SHADER_FRAGMENT, "E:/Code/WRayEngine/WRayEngine/WRayEngine/test.frag", "main");
    info.shaderStages[0] = vertexShader.shaderStage;
    info.shaderStages[1] = fragmentShader.shaderStage;

    init_framebuffers(info, depthPresent);
    //init_vertex_buffer(info, g_vb_texture_Data, sizeof(g_vb_texture_Data), sizeof(g_vb_texture_Data[0]), true);
    vertexBuffer.init(info.device, Buffer::Type::BUFFER_VERTEX, g_vb_texture_Data, sizeof(g_vb_texture_Data), sizeof(g_vb_texture_Data[0]), info.memory_properties, true);
    info.vi_attribs[0] = vertexBuffer.vi_attribs[0];
    info.vi_attribs[1] = vertexBuffer.vi_attribs[1];
    info.vi_binding = vertexBuffer.vi_binding;

    init_descriptor_pool(info, true);
    init_descriptor_set(info, true);
    init_pipeline_cache(info);
    init_pipeline(info, depthPresent);
    //init_presentable_image(info);

    VkClearValue clear_values[2];
    init_clear_color_and_depth(info, clear_values);

    VkRenderPassBeginInfo rp_begin;
    init_render_pass_begin_info(info, rp_begin);
    rp_begin.clearValueCount = 2;
    rp_begin.pClearValues = clear_values;
    /*
    vkCmdBeginRenderPass(info.cmd, &rp_begin, VK_SUBPASS_CONTENTS_INLINE);

    vkCmdBindPipeline(info.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, info.pipeline);
    vkCmdBindDescriptorSets(info.cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, info.pipeline_layout, 0, NUM_DESCRIPTOR_SETS,
        info.desc_set.data(), 0, NULL);

    const VkDeviceSize offsets[1] = { 0 };
    vkCmdBindVertexBuffers(info.cmd, 0, 1, &info.vertex_buffer.buf, offsets);

    init_viewports(info);
    init_scissors(info);

    vkCmdDraw(info.cmd, 12 * 3, 1, 0, 0);
    vkCmdEndRenderPass(info.cmd);
    res = vkEndCommandBuffer(info.cmd);
    assert(res == VK_SUCCESS);*/

    //VkFence drawFence = {};
    //init_fence(info, drawFence);
    //VkPipelineStageFlags pipe_stage_flags = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    //VkSubmitInfo submit_info = {};
    //init_submit_info(info, submit_info, pipe_stage_flags);

    ///* Queue the command buffer for execution */
    //res = vkQueueSubmit(info.graphics_queue, 1, &submit_info, drawFence);
    //assert(res == VK_SUCCESS);

    ///* Now present the image in the window */
    //VkPresentInfoKHR present = {};
    //init_present_info(info, present);

    ///* Make sure command buffer is finished before presenting */
    //do {
    //    res = vkWaitForFences(info.device, 1, &drawFence, VK_TRUE, FENCE_TIMEOUT);
    //} while (res == VK_TIMEOUT);
    //assert(res == VK_SUCCESS);
    //res = vkQueuePresentKHR(info.present_queue, &present);
    //assert(res == VK_SUCCESS);

    //wait_seconds(1);
    //if (info.save_images) write_ppm(info, "template");

}

void Application::update()
{
    acquireSemaphore();
    render();
    present();


    MSG msg;
    HWND handle;
    while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

    handle = GetActiveWindow();
}

void Application::destroy()
{
    vkDestroyFence(info.device, drawFence, NULL);
    vkDestroySemaphore(info.device, info.imageAcquiredSemaphore, NULL);
    destroy_pipeline(info);
    destroy_pipeline_cache(info);
    destroy_textures(info);
    destroy_descriptor_pool(info);
    //destroy_vertex_buffer(info);
    vertexBuffer.destroy(info.device);
    destroy_framebuffers(info);
    //destroy_shaders(info);
    vertexShader.destroy(info.device);
    fragmentShader.destroy(info.device);
    destroy_renderpass(info);
    destroy_descriptor_and_pipeline_layouts(info);
    destroy_uniform_buffer(info);
    destroy_depth_buffer(info);
    destroy_swap_chain(info);
    //destroy_command_buffer(info);
    //destroy_command_pool(info);
    destroy_device(info);
    destroy_window(info);
    destroy_instance(info);
}

void Application::acquireSemaphore()
{
    // acquire semaphore
    VkSemaphore acquire_semaphore;
    if (recycled_semaphores.empty())
    {
        VkSemaphoreCreateInfo infos = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
        vkCreateSemaphore(info.device, &infos, nullptr, &acquire_semaphore);
    }
    else
    {
        acquire_semaphore = recycled_semaphores.back();
        recycled_semaphores.pop_back();
    }

    VkResult res = vkAcquireNextImageKHR(info.device, info.swap_chain, UINT64_MAX, acquire_semaphore, VK_NULL_HANDLE, &info.current_buffer);

    if (res != VK_SUCCESS)
    {
        recycled_semaphores.push_back(acquire_semaphore);
        return;
    }


    // If we have outstanding fences for this swapchain image, wait for them to complete first.
    // After begin frame returns, it is safe to reuse or delete resources which
    // were used previously.
    //
    // We wait for fences which completes N frames earlier, so we do not stall,
    // waiting for all GPU work to complete before this returns.
    // Normally, this doesn't really block at all,
    // since we're waiting for old frames to have been completed, but just in case.
    if (info.per_frame[info.current_buffer].queue_submit_fence != VK_NULL_HANDLE)
    {
        vkWaitForFences(info.device, 1, &info.per_frame[info.current_buffer].queue_submit_fence, true, UINT64_MAX);
        vkResetFences(info.device, 1, &info.per_frame[info.current_buffer].queue_submit_fence);
    }

    if (info.per_frame[info.current_buffer].primary_command_pool != VK_NULL_HANDLE)
    {
        vkResetCommandPool(info.device, info.per_frame[info.current_buffer].primary_command_pool, 0);
    }

    // Recycle the old semaphore back into the semaphore manager.
    VkSemaphore old_semaphore = info.per_frame[info.current_buffer].swapchain_acquire_semaphore;

    if (old_semaphore != VK_NULL_HANDLE)
    {
        recycled_semaphores.push_back(old_semaphore);
    }

    info.per_frame[info.current_buffer].swapchain_acquire_semaphore = acquire_semaphore;

    //return VK_SUCCESS;
}

void Application::updateCPUData()
{
    float fov = glm::radians(45.0f);
    info.Projection = glm::perspective(fov, static_cast<float>(info.width) / static_cast<float>(info.height), 0.1f, 100.0f);
    static float offset = 0.f;
    info.View = glm::lookAt(glm::vec3(-5, 3, -10+ offset),  // Camera is at (-5,3,-10), in World Space
        glm::vec3(0, 0, 0),     // and looks at the origin
        glm::vec3(0, -1, 0)     // Head is up (set to 0,-1,0 to look upside-down)
    );
    offset += 0.01f;

    info.Model = glm::mat4(1.0f);
    // Vulkan clip space has inverted Y and half Z.
    info.Clip = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.5f, 1.0f);

    info.MVP = info.Clip * info.Projection * info.View * info.Model;
}

void Application::updateTexture()
{
    static bool initialized = false;
    if (initialized)
    {
        return;
    }

    //init_texture(info);
    initialized = true;
}

void Application::render()
{
    updateTexture();
    updateCPUData();

    // update uniform buffer
    {
        uint8_t* pData;
        VkResult res = vkMapMemory(info.device, info.uniform_data.mem, 0, info.uniform_data.buffer_info.range, 0, (void**)&pData);
        assert(res == VK_SUCCESS);
        memcpy(pData, &info.MVP, sizeof(info.MVP));

        //vkUnmapMemory(info.device, info.uniform_data.mem);
        VkMappedMemoryRange range;
        range.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
        range.offset = 0;
        range.pNext = NULL;
        range.size = info.uniform_data.buffer_info.range;
        range.memory = info.uniform_data.mem;
        vkInvalidateMappedMemoryRanges(info.device, 1, &range);
        vkFlushMappedMemoryRanges(info.device, 1, &range);
    }

    // Render to this framebuffer.
    VkFramebuffer framebuffer = info.framebuffers[info.current_buffer];

    // Allocate or re-use a primary command buffer.
    VkCommandBuffer cmd = info.per_frame[info.current_buffer].primary_command_buffer;

    // We will only submit this once before it's recycled.
    VkCommandBufferBeginInfo begin_info{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    // Begin command recording
    vkBeginCommandBuffer(cmd, &begin_info);

    // Set clear color values.
    VkClearValue clear_value[2];
    static float c = 0;
    clear_value[0].color = { {0.1f, 0.2f, c+0.2f, 1.0f} };
    clear_value[1].depthStencil.depth = 1;
    clear_value[1].depthStencil.stencil = 0;
    c += 0.01f;

    // Begin the render pass.
    VkRenderPassBeginInfo rp_begin{ VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO };
    rp_begin.renderPass = info.render_pass;
    rp_begin.framebuffer = framebuffer;
    rp_begin.renderArea.extent.width = info.width;
    rp_begin.renderArea.extent.height = info.height;
    rp_begin.clearValueCount = 2;
    rp_begin.pClearValues = clear_value;
    // We will add draw commands in the same command buffer.
    vkCmdBeginRenderPass(cmd, &rp_begin, VK_SUBPASS_CONTENTS_INLINE);

    // Bind the graphics pipeline.
    vkCmdBindPipeline(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, info.pipeline);

    VkViewport vp{};
    vp.width = static_cast<float>(info.width);
    vp.height = static_cast<float>(info.height);
    vp.minDepth = 0.0f;
    vp.maxDepth = 1.0f;
    // Set viewport dynamically
    vkCmdSetViewport(cmd, 0, 1, &vp);

    VkRect2D scissor{};
    scissor.extent.width = info.width;
    scissor.extent.height = info.height;
    // Set scissor dynamically
    vkCmdSetScissor(cmd, 0, 1, &scissor);

    vkCmdBindDescriptorSets(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, info.pipeline_layout, 0, NUM_DESCRIPTOR_SETS,
        info.desc_set.data(), 0, NULL);

    const VkDeviceSize offsets[1] = { 0 };
    //vkCmdBindVertexBuffers(cmd, 0, 1, &info.vertex_buffer.buf, offsets);
    vkCmdBindVertexBuffers(cmd, 0, 1, &vertexBuffer.buf, offsets);
    // Draw three vertices with one instance.
    vkCmdDraw(cmd, 12 * 3, 1, 0, 0);
    //vkCmdDraw(cmd, 3, 1, 0, 0);

    // Complete render pass.
    vkCmdEndRenderPass(cmd);

    // Complete the command buffer.
    VK_CHECK(vkEndCommandBuffer(cmd));

}

void Application::present()
{
    VkCommandBuffer cmd = info.per_frame[info.current_buffer].primary_command_buffer;

    // Submit it to the queue with a release semaphore.
    if (info.per_frame[info.current_buffer].swapchain_release_semaphore == VK_NULL_HANDLE)
    {
        VkSemaphoreCreateInfo semaphore_info{ VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
        VK_CHECK(vkCreateSemaphore(info.device, &semaphore_info, nullptr,
            &info.per_frame[info.current_buffer].swapchain_release_semaphore));
    }

    VkPipelineStageFlags wait_stage{ VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };

    VkSubmitInfo infoS{ VK_STRUCTURE_TYPE_SUBMIT_INFO };
    infoS.commandBufferCount = 1;
    infoS.pCommandBuffers = &cmd;
    infoS.waitSemaphoreCount = 1;
    infoS.pWaitSemaphores = &info.per_frame[info.current_buffer].swapchain_acquire_semaphore;
    infoS.pWaitDstStageMask = &wait_stage;
    infoS.signalSemaphoreCount = 1;
    infoS.pSignalSemaphores = &info.per_frame[info.current_buffer].swapchain_release_semaphore;
    // Submit command buffer to graphics queue
    VK_CHECK(vkQueueSubmit(info.present_queue, 1, &infoS, info.per_frame[info.current_buffer].queue_submit_fence));

    VkPresentInfoKHR present{ VK_STRUCTURE_TYPE_PRESENT_INFO_KHR };
    present.swapchainCount = 1;
    present.pSwapchains = &info.swap_chain;
    present.pImageIndices = &info.current_buffer;
    present.waitSemaphoreCount = 1;
    present.pWaitSemaphores = &info.per_frame[info.current_buffer].swapchain_release_semaphore;
    // Present swapchain image
    vkQueuePresentKHR(info.present_queue, &present);
}

