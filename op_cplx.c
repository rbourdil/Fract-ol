#include "img.h"

void	add_cplx(t_cplx *cplx1, t_cplx cplx2)
{
	cplx1->a += cplx2.a;
	cplx1->b += cplx2.b;
}

void	mult_cplx(t_cplx *cplx1, t_cplx cplx2)
{
	double	tmp;

	tmp = cplx1->a;
	cplx1->a = cplx1->a * cplx2.a - cplx1->b * cplx2.b;
	cplx1->b = tmp * cplx2.b + cplx2.a * cplx1->b;
}

double	mod_cplx(t_cplx cplx1)
{
	return (sqrt(cplx1.a * cplx1.a + cplx1.b * cplx1.b));
}
