
#define INFINITY (__builtin_inff())
#define NAN (__builtin_nanf(""))
typedef long unsigned int size_t;
#define half _Float16
extern "C" __attribute__((device, const)) size_t __ockl_get_local_id(unsigned int);
extern "C" __attribute__((device, const)) size_t __ockl_get_group_id(unsigned int);
extern "C" __attribute__((device, const)) size_t __ockl_get_local_size(unsigned int);
extern "C" __attribute__((device, const)) float __ocml_fmax_f32(float, float);
extern "C" __attribute__((device, pure)) float __ocml_exp2_f32(float);
extern "C" __attribute__((device, pure)) float __ocml_log2_f32(float);
extern "C" __attribute__((device, const)) float __ocml_sqrt_f32(float);
extern "C" __attribute__((device)) float __ocml_sin_f32(float);
extern "C" __attribute__((device, const)) double __ocml_fmax_f64(double, double);
extern "C" __attribute__((device, pure)) double __ocml_exp2_f64(double);
extern "C" __attribute__((device, pure)) double __ocml_log2_f64(double);
extern "C" __attribute__((device, const)) double __ocml_sqrt_f64(double);
extern "C" __attribute__((device)) double __ocml_sin_f64(double);
extern "C" __attribute__((device, const)) half __ocml_fmax_f16(half, half);
extern "C" __attribute__((device, pure)) half __ocml_exp2_f16(half);
extern "C" __attribute__((device, pure)) half __ocml_log2_f16(half);
extern "C" __attribute__((device, const)) half __ocml_sqrt_f16(half);
extern "C" __attribute__((device)) half __ocml_sin_f16(half);
extern "C" __attribute__((global))void __attribute__((amdgpu_flat_work_group_size(1, 3)))E_325_3_3(float* data0, float* data1) {
  int gidx0 = __ockl_get_group_id(0); /* 325 */
  int lidx0 = __ockl_get_local_id(0); /* 3 */
  int alu0 = ((gidx0*9)+(lidx0*3));
  float val0 = *(data1+alu0);
  int alu1 = (alu0+1);
  float val1 = *(data1+alu1);
  int alu2 = (alu0+2);
  float val2 = *(data1+alu2);
  float alu3 = (((bool)(val1))?((val1<0.0f)?-1.0f:1.0f):0.0f);
  float alu4 = (val1*alu3);
  *(data0+alu1) = (1.5707963267948966f-((1.5707963267948966f-(__ocml_sqrt_f32((1.0f-alu4))*((((((((((((((alu4*-0.0012624911f)+0.0066700901f)*alu4)+-0.0170881256f)*alu4)+0.030891881f)*alu4)+-0.0501743046f)*alu4)+0.0889789874f)*alu4)+-0.2145988016f)*alu4)+1.570796305f)))*alu3));
  float alu6 = (((bool)(val2))?((val2<0.0f)?-1.0f:1.0f):0.0f);
  float alu7 = (val2*alu6);
  *(data0+alu2) = (1.5707963267948966f-((1.5707963267948966f-(__ocml_sqrt_f32((1.0f-alu7))*((((((((((((((alu7*-0.0012624911f)+0.0066700901f)*alu7)+-0.0170881256f)*alu7)+0.030891881f)*alu7)+-0.0501743046f)*alu7)+0.0889789874f)*alu7)+-0.2145988016f)*alu7)+1.570796305f)))*alu6));
  float alu9 = (((bool)(val0))?((val0<0.0f)?-1.0f:1.0f):0.0f);
  float alu10 = (val0*alu9);
  *(data0+alu0) = (1.5707963267948966f-((1.5707963267948966f-(__ocml_sqrt_f32((1.0f-alu10))*((((((((((((((alu10*-0.0012624911f)+0.0066700901f)*alu10)+-0.0170881256f)*alu10)+0.030891881f)*alu10)+-0.0501743046f)*alu10)+0.0889789874f)*alu10)+-0.2145988016f)*alu10)+1.570796305f)))*alu9));
}
