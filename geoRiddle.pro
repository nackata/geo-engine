QT += core
QT -= gui

TARGET = geoRiddle
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    lib/glad/src/glad.c \
    lib/glm/detail/glm.cpp \
    src/fpsCam.cpp \
    src/mesh.cpp \
    src/model.cpp \
    src/shader.cpp \
    src/sceneobject.cpp \
    src/renderer.cpp \
    src/dynamicobject.cpp \
    src/rotatingcube.cpp \
    src/scene.cpp \
    src/game.cpp \
    src/dynamicinter.cpp \
    src/button.cpp \
    src/player.cpp \
    src/inputmanager.cpp \
    src/aabbtritest.cpp \
    src/stand.cpp \
    src/attachedbutton.cpp \
    src/screentext.cpp \
    src/soundmaster.cpp

HEADERS += \
    include/fpsCam.h \
    include/mesh.h \
    include/model.h \
    include/shader.h \
    include/stb_image.h \
    include/sceneobject.h \
    include/staticobject.h \
    include/room.h \
    include/light.h \
    include/renderer.h \
    include/dynamicobject.h \
    include/rotatingcube.h \
    include/scene.h \
    include/dynamicnoninter.h \
    include/game.h \
    include/dynamicinter.h \
    include/button.h \
    include/player.h \
    include/aabb.h \
    include/inputmanager.h \
    include/color.h \
    include/stand.h \
    include/attachedbutton.h \
    include/tojsonconvert.h \
    include/screentext.h \
    include/soundmaster.h \
    lib/glad/include/KHR/khrplatform.h \
    lib/glad/include/glad/glad.h \
    lib/glfw-3.3.bin.WIN64/include/GLFW/glfw3.h \
    lib/glfw-3.3.bin.WIN64/include/GLFW/glfw3native.h \
    lib/glm/common.hpp \
    lib/glm/detail/_features.hpp \
    lib/glm/detail/_fixes.hpp \
    lib/glm/detail/_noise.hpp \
    lib/glm/detail/_swizzle.hpp \
    lib/glm/detail/_swizzle_func.hpp \
    lib/glm/detail/_vectorize.hpp \
    lib/glm/detail/compute_common.hpp \
    lib/glm/detail/compute_vector_relational.hpp \
    lib/glm/detail/qualifier.hpp \
    lib/glm/detail/setup.hpp \
    lib/glm/detail/type_float.hpp \
    lib/glm/detail/type_half.hpp \
    lib/glm/detail/type_mat2x2.hpp \
    lib/glm/detail/type_mat2x3.hpp \
    lib/glm/detail/type_mat2x4.hpp \
    lib/glm/detail/type_mat3x2.hpp \
    lib/glm/detail/type_mat3x3.hpp \
    lib/glm/detail/type_mat3x4.hpp \
    lib/glm/detail/type_mat4x2.hpp \
    lib/glm/detail/type_mat4x3.hpp \
    lib/glm/detail/type_mat4x4.hpp \
    lib/glm/detail/type_quat.hpp \
    lib/glm/detail/type_vec1.hpp \
    lib/glm/detail/type_vec2.hpp \
    lib/glm/detail/type_vec3.hpp \
    lib/glm/detail/type_vec4.hpp \
    lib/glm/exponential.hpp \
    lib/glm/ext.hpp \
    lib/glm/ext/matrix_clip_space.hpp \
    lib/glm/ext/matrix_common.hpp \
    lib/glm/ext/matrix_double2x2.hpp \
    lib/glm/ext/matrix_double2x2_precision.hpp \
    lib/glm/ext/matrix_double2x3.hpp \
    lib/glm/ext/matrix_double2x3_precision.hpp \
    lib/glm/ext/matrix_double2x4.hpp \
    lib/glm/ext/matrix_double2x4_precision.hpp \
    lib/glm/ext/matrix_double3x2.hpp \
    lib/glm/ext/matrix_double3x2_precision.hpp \
    lib/glm/ext/matrix_double3x3.hpp \
    lib/glm/ext/matrix_double3x3_precision.hpp \
    lib/glm/ext/matrix_double3x4.hpp \
    lib/glm/ext/matrix_double3x4_precision.hpp \
    lib/glm/ext/matrix_double4x2.hpp \
    lib/glm/ext/matrix_double4x2_precision.hpp \
    lib/glm/ext/matrix_double4x3.hpp \
    lib/glm/ext/matrix_double4x3_precision.hpp \
    lib/glm/ext/matrix_double4x4.hpp \
    lib/glm/ext/matrix_double4x4_precision.hpp \
    lib/glm/ext/matrix_float2x2.hpp \
    lib/glm/ext/matrix_float2x2_precision.hpp \
    lib/glm/ext/matrix_float2x3.hpp \
    lib/glm/ext/matrix_float2x3_precision.hpp \
    lib/glm/ext/matrix_float2x4.hpp \
    lib/glm/ext/matrix_float2x4_precision.hpp \
    lib/glm/ext/matrix_float3x2.hpp \
    lib/glm/ext/matrix_float3x2_precision.hpp \
    lib/glm/ext/matrix_float3x3.hpp \
    lib/glm/ext/matrix_float3x3_precision.hpp \
    lib/glm/ext/matrix_float3x4.hpp \
    lib/glm/ext/matrix_float3x4_precision.hpp \
    lib/glm/ext/matrix_float4x2.hpp \
    lib/glm/ext/matrix_float4x2_precision.hpp \
    lib/glm/ext/matrix_float4x3.hpp \
    lib/glm/ext/matrix_float4x3_precision.hpp \
    lib/glm/ext/matrix_float4x4.hpp \
    lib/glm/ext/matrix_float4x4_precision.hpp \
    lib/glm/ext/matrix_projection.hpp \
    lib/glm/ext/matrix_relational.hpp \
    lib/glm/ext/matrix_transform.hpp \
    lib/glm/ext/quaternion_common.hpp \
    lib/glm/ext/quaternion_double.hpp \
    lib/glm/ext/quaternion_double_precision.hpp \
    lib/glm/ext/quaternion_exponential.hpp \
    lib/glm/ext/quaternion_float.hpp \
    lib/glm/ext/quaternion_float_precision.hpp \
    lib/glm/ext/quaternion_geometric.hpp \
    lib/glm/ext/quaternion_relational.hpp \
    lib/glm/ext/quaternion_transform.hpp \
    lib/glm/ext/quaternion_trigonometric.hpp \
    lib/glm/ext/scalar_common.hpp \
    lib/glm/ext/scalar_constants.hpp \
    lib/glm/ext/scalar_int_sized.hpp \
    lib/glm/ext/scalar_relational.hpp \
    lib/glm/ext/scalar_uint_sized.hpp \
    lib/glm/ext/scalar_ulp.hpp \
    lib/glm/ext/vector_bool1.hpp \
    lib/glm/ext/vector_bool1_precision.hpp \
    lib/glm/ext/vector_bool2.hpp \
    lib/glm/ext/vector_bool2_precision.hpp \
    lib/glm/ext/vector_bool3.hpp \
    lib/glm/ext/vector_bool3_precision.hpp \
    lib/glm/ext/vector_bool4.hpp \
    lib/glm/ext/vector_bool4_precision.hpp \
    lib/glm/ext/vector_common.hpp \
    lib/glm/ext/vector_double1.hpp \
    lib/glm/ext/vector_double1_precision.hpp \
    lib/glm/ext/vector_double2.hpp \
    lib/glm/ext/vector_double2_precision.hpp \
    lib/glm/ext/vector_double3.hpp \
    lib/glm/ext/vector_double3_precision.hpp \
    lib/glm/ext/vector_double4.hpp \
    lib/glm/ext/vector_double4_precision.hpp \
    lib/glm/ext/vector_float1.hpp \
    lib/glm/ext/vector_float1_precision.hpp \
    lib/glm/ext/vector_float2.hpp \
    lib/glm/ext/vector_float2_precision.hpp \
    lib/glm/ext/vector_float3.hpp \
    lib/glm/ext/vector_float3_precision.hpp \
    lib/glm/ext/vector_float4.hpp \
    lib/glm/ext/vector_float4_precision.hpp \
    lib/glm/ext/vector_int1.hpp \
    lib/glm/ext/vector_int1_precision.hpp \
    lib/glm/ext/vector_int2.hpp \
    lib/glm/ext/vector_int2_precision.hpp \
    lib/glm/ext/vector_int3.hpp \
    lib/glm/ext/vector_int3_precision.hpp \
    lib/glm/ext/vector_int4.hpp \
    lib/glm/ext/vector_int4_precision.hpp \
    lib/glm/ext/vector_relational.hpp \
    lib/glm/ext/vector_uint1.hpp \
    lib/glm/ext/vector_uint1_precision.hpp \
    lib/glm/ext/vector_uint2.hpp \
    lib/glm/ext/vector_uint2_precision.hpp \
    lib/glm/ext/vector_uint3.hpp \
    lib/glm/ext/vector_uint3_precision.hpp \
    lib/glm/ext/vector_uint4.hpp \
    lib/glm/ext/vector_uint4_precision.hpp \
    lib/glm/ext/vector_ulp.hpp \
    lib/glm/fwd.hpp \
    lib/glm/geometric.hpp \
    lib/glm/glm.hpp \
    lib/glm/gtc/bitfield.hpp \
    lib/glm/gtc/color_space.hpp \
    lib/glm/gtc/constants.hpp \
    lib/glm/gtc/epsilon.hpp \
    lib/glm/gtc/integer.hpp \
    lib/glm/gtc/matrix_access.hpp \
    lib/glm/gtc/matrix_integer.hpp \
    lib/glm/gtc/matrix_inverse.hpp \
    lib/glm/gtc/matrix_transform.hpp \
    lib/glm/gtc/noise.hpp \
    lib/glm/gtc/packing.hpp \
    lib/glm/gtc/quaternion.hpp \
    lib/glm/gtc/random.hpp \
    lib/glm/gtc/reciprocal.hpp \
    lib/glm/gtc/round.hpp \
    lib/glm/gtc/type_aligned.hpp \
    lib/glm/gtc/type_precision.hpp \
    lib/glm/gtc/type_ptr.hpp \
    lib/glm/gtc/ulp.hpp \
    lib/glm/gtc/vec1.hpp \
    lib/glm/gtx/associated_min_max.hpp \
    lib/glm/gtx/bit.hpp \
    lib/glm/gtx/closest_point.hpp \
    lib/glm/gtx/color_encoding.hpp \
    lib/glm/gtx/color_space.hpp \
    lib/glm/gtx/color_space_YCoCg.hpp \
    lib/glm/gtx/common.hpp \
    lib/glm/gtx/compatibility.hpp \
    lib/glm/gtx/component_wise.hpp \
    lib/glm/gtx/dual_quaternion.hpp \
    lib/glm/gtx/easing.hpp \
    lib/glm/gtx/euler_angles.hpp \
    lib/glm/gtx/extend.hpp \
    lib/glm/gtx/extended_min_max.hpp \
    lib/glm/gtx/exterior_product.hpp \
    lib/glm/gtx/fast_exponential.hpp \
    lib/glm/gtx/fast_square_root.hpp \
    lib/glm/gtx/fast_trigonometry.hpp \
    lib/glm/gtx/functions.hpp \
    lib/glm/gtx/gradient_paint.hpp \
    lib/glm/gtx/handed_coordinate_space.hpp \
    lib/glm/gtx/hash.hpp \
    lib/glm/gtx/integer.hpp \
    lib/glm/gtx/intersect.hpp \
    lib/glm/gtx/io.hpp \
    lib/glm/gtx/log_base.hpp \
    lib/glm/gtx/matrix_cross_product.hpp \
    lib/glm/gtx/matrix_decompose.hpp \
    lib/glm/gtx/matrix_factorisation.hpp \
    lib/glm/gtx/matrix_interpolation.hpp \
    lib/glm/gtx/matrix_major_storage.hpp \
    lib/glm/gtx/matrix_operation.hpp \
    lib/glm/gtx/matrix_query.hpp \
    lib/glm/gtx/matrix_transform_2d.hpp \
    lib/glm/gtx/mixed_product.hpp \
    lib/glm/gtx/norm.hpp \
    lib/glm/gtx/normal.hpp \
    lib/glm/gtx/normalize_dot.hpp \
    lib/glm/gtx/number_precision.hpp \
    lib/glm/gtx/optimum_pow.hpp \
    lib/glm/gtx/orthonormalize.hpp \
    lib/glm/gtx/perpendicular.hpp \
    lib/glm/gtx/polar_coordinates.hpp \
    lib/glm/gtx/projection.hpp \
    lib/glm/gtx/quaternion.hpp \
    lib/glm/gtx/range.hpp \
    lib/glm/gtx/raw_data.hpp \
    lib/glm/gtx/rotate_normalized_axis.hpp \
    lib/glm/gtx/rotate_vector.hpp \
    lib/glm/gtx/scalar_multiplication.hpp \
    lib/glm/gtx/scalar_relational.hpp \
    lib/glm/gtx/spline.hpp \
    lib/glm/gtx/std_based_type.hpp \
    lib/glm/gtx/string_cast.hpp \
    lib/glm/gtx/texture.hpp \
    lib/glm/gtx/transform.hpp \
    lib/glm/gtx/transform2.hpp \
    lib/glm/gtx/type_aligned.hpp \
    lib/glm/gtx/type_trait.hpp \
    lib/glm/gtx/vec_swizzle.hpp \
    lib/glm/gtx/vector_angle.hpp \
    lib/glm/gtx/vector_query.hpp \
    lib/glm/gtx/wrap.hpp \
    lib/glm/integer.hpp \
    lib/glm/mat2x2.hpp \
    lib/glm/mat2x3.hpp \
    lib/glm/mat2x4.hpp \
    lib/glm/mat3x2.hpp \
    lib/glm/mat3x3.hpp \
    lib/glm/mat3x4.hpp \
    lib/glm/mat4x2.hpp \
    lib/glm/mat4x3.hpp \
    lib/glm/mat4x4.hpp \
    lib/glm/matrix.hpp \
    lib/glm/packing.hpp \
    lib/glm/simd/common.h \
    lib/glm/simd/exponential.h \
    lib/glm/simd/geometric.h \
    lib/glm/simd/integer.h \
    lib/glm/simd/matrix.h \
    lib/glm/simd/packing.h \
    lib/glm/simd/platform.h \
    lib/glm/simd/trigonometric.h \
    lib/glm/simd/vector_relational.h \
    lib/glm/trigonometric.hpp \
    lib/glm/vec2.hpp \
    lib/glm/vec3.hpp \
    lib/glm/vec4.hpp \
    lib/glm/vector_relational.hpp

DISTFILES += \
    common/shaders/fragment_shader.glsl \
    common/shaders/lamp_shader.glsl \
    common/shaders/vertex_shader.glsl \
    common/shaders/text_frag.glsl \
    common/shaders/text_vs.glsl


#LIBS += -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor -lassimp -lpng -lz

LIBS += -lgdi32 -lopengl32 -luser32 -lkernel32 -lglu32

INCLUDEPATH += $$PWD/lib/glad/include
INCLUDEPATH += $$PWD/lib

win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/Assimp/lib/x64/ -lassimp-vc141-mtd

INCLUDEPATH += $$PWD/lib/Assimp/include
DEPENDPATH += $$PWD/lib/Assimp/include/assimp


win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/freetype/win64/ -lfreetype

INCLUDEPATH += $$PWD/lib/freetype/include
DEPENDPATH += $$PWD/lib/freetype/include

win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/irrKlang-64bit-1.6.0/lib/Winx64-visualStudio/ -lirrKlang

INCLUDEPATH += $$PWD/lib/irrKlang-64bit-1.6.0/include
DEPENDPATH += $$PWD/lib/irrKlang-64bit-1.6.0/include

win32: LIBS += -L$$PWD/lib/glfw-3.3.bin.WIN64/lib-vc2017/ -lglfw3dll

INCLUDEPATH += $$PWD/lib/glfw-3.3.bin.WIN64/include
DEPENDPATH += $$PWD/lib/glfw-3.3.bin.WIN364/include
