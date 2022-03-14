#include "img.h"

int	main(void)
{
	t_cplx	cplx1;
	t_cplx	cplx2;

	cplx1.a = 0.0;
	cplx1.b = 1.0;
	cplx2.a = 3.0; 
	cplx2.b = 2.0;

	mult_cplx(&cplx1, &cplx2);
	printf("%f + %fi\n", cplx1.a, cplx1.b);
	return (0);
}
