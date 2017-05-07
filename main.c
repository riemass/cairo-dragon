#include <stdlib.h>

#include <cairo.h>
#include <cairo-svg.h>
#include <cairo-pdf.h>

#define SIZE_H 640
#define SIZE_V 360

void dragon_draw(int, int, int, int);
void dragon_r(cairo_t * cr, int depth, short *x,short *y);
void dragon_l(cairo_t * cr, int depth, short *x,short *y);

void dragon_l(cairo_t * cr, int depth, short *x,short *y)
{
  if (depth != 0)
    dragon_l(cr, depth-1, x, y);
  short t = *x; *x = *y; *y = -t; 
  cairo_rel_line_to(cr, *x, *y);

  if (depth != 0)
    dragon_r(cr, depth - 1, x, y);
}

void dragon_r(cairo_t * cr, int depth, short *x,short *y)
{
  if (depth != 0)
    dragon_l(cr, depth-1, x, y);
  short t = *x; *x = -*y; *y = t; 
  cairo_rel_line_to(cr, *x, *y);
  if (depth != 0)
    dragon_r(cr, depth -1, x, y);
}


int main(int argc, char **argv)
{
	int h_size = SIZE_H;
	int v_size = SIZE_V;
	int line_len = 3;
	int n = 2;

        n = atoi(argv[1]);
	
	dragon_draw(h_size, v_size, line_len, n);

	return 0;
}
	
void dragon_draw(int h_size, int v_size, int line_len, int depth)
{
	cairo_surface_t *surface;
	surface = cairo_svg_surface_create("dragon.svg", h_size, v_size);
	cairo_t * cr;
	cr = cairo_create(surface);
	
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width(cr, 0.5);
	cairo_move_to(cr, h_size/2, v_size/2);

	short x = -line_len, y = 0;

        cairo_rel_line_to(cr, x, y);

        dragon_l(cr, depth, &x, &y);
	
	cairo_stroke(cr);	
	cairo_destroy(cr);	
	cairo_surface_destroy(surface);
}

