# Acceso a pixels

## Clase cv::Mat

```
class CV_EXPORTS Mat
{
public:

    /*! includes several bit-fields:
         - the magic signature
         - continuity flag
         - depth
         - number of channels
     */
    int flags;

    //! the array dimensionality, >= 2
    int dims;

    //! the number of rows and columns or (-1, -1) when more than 2 dimensions
    int rows, cols;

    //! pointer to the data
    uchar* data;

    //! pointer to the reference counter;
    // when array points to user-allocated data, the pointer is NULL
    int* refcount;

    // other members
    ...
};
```


## Clase cv::Vec

Representa un vector (matriz unidimensional) parametrizable con el tipo (_Tp) y 
el número (n) de los elementos. 

Hay predefinidos tipos _VecNt_ donde N es el número de elementos y t es el tipo 
básico de elemento (b=byte, s=short, i=int, f=float, d=double).

_Vec3b_ es usado para definir las 3 componentes RGB de un pixel.

Se usa el operador _[]_ para acceder a los elementos del vector.

```
template<typename _Tp, int n> class Vec : public Matx<_Tp, n, 1> {...};

typedef Vec<uchar, 2> Vec2b; // 2 uint8_t
typedef Vec<uchar, 3> Vec3b; // 3 uint8_t
typedef Vec<uchar, 4> Vec4b; // 4 uint8_t

typedef Vec<short, 2> Vec2s; // 2 int16_t
typedef Vec<short, 3> Vec3s; // 3 int16_t
typedef Vec<short, 4> Vec4s; // 4 int16_t

typedef Vec<int, 2> Vec2i; // 2 int32_t
typedef Vec<int, 3> Vec3i; // 3 int32_t
typedef Vec<int, 4> Vec4i; // 4 int32_t

typedef Vec<float, 2> Vec2f; // 2 float
typedef Vec<float, 3> Vec3f; // 3 float
typedef Vec<float, 4> Vec4f; // 4 float
typedef Vec<float, 6> Vec6f; // 6 float

typedef Vec<double, 2> Vec2d; // 2 double
typedef Vec<double, 3> Vec3d; // 3 double
typedef Vec<double, 4> Vec4d; // 4 double
typedef Vec<double, 6> Vec6d; // 6 double
```


