#ifndef AGG_API_H_INCLUDED
#define AGG_API_H_INCLUDED

#include "general.h"
#include "inttypes.h"

#define API_AGG DLLPUBLIC

/* + */
/* Line caps */
#define CAP_BUTT            1
#define CAP_SQUARE          2
#define CAP_ROUND           3

/* Line joins */
#define JOIN_MITER          5
#define JOIN_MITER_REV      6
#define JOIN_ROUND          7
#define JOIN_BEVEL          8
#define JOIN_MITER_ROUND    9

/* Text attributes */
#define TEXT_LTR            10
#define TEXT_RTL            11
#define TEXT_TTB            12
#define TEXT_BTT            13
/* - */

EXTERNC_BEGIN

typedef int gcid_t;

API_AGG
gcid_t
make_gc(void);

API_AGG
void
gc_attach_buffer(gcid_t, uint8 *, unsigned width, unsigned height, 
                                                                int stride);
API_AGG
void
gc_trans_save(gcid_t);

API_AGG
void
gc_trans_restore(gcid_t);

API_AGG
void
gc_(gcid_t);

API_AGG
void
gc_trans_identity(gcid_t);

API_AGG
void
gc_trans_rotate(gcid_t, double angle);

API_AGG
void
gc_trans_scale(gcid_t, double sx, double sy);

API_AGG
void
gc_trans_offset(gcid_t, double tx, double ty);

API_AGG
void
gc_clear_bg(gcid_t);

API_AGG
void
gc_set_color_bg(gcid_t, uint32);

API_AGG
void
gc_set_color_fill(gcid_t, uint32);

API_AGG
void
gc_set_color_stroke(gcid_t, uint32);

API_AGG
void
gc_set_stroke_width(gcid_t, double);

API_AGG
void
gc_style_save(gcid_t);

API_AGG
void
gc_style_restore(gcid_t);

API_AGG
void
gc_set_line_cap(gcid_t, int);

API_AGG
void
gc_set_line_join(gcid_t, int);

API_AGG
int
gc_get_antialiasing(gcid_t);

API_AGG
void
gc_set_antialiasing(gcid_t, int);

API_AGG
double
gc_get_stroke_width(gcid_t);

API_AGG
int
gc_get_line_join(gcid_t);

API_AGG
int
gc_get_line_cap(gcid_t);

API_AGG
uint32
gc_get_color_bg(gcid_t);

API_AGG
uint32
gc_get_color_fill(gcid_t);

API_AGG
uint32
gc_get_color_stroke(gcid_t);

API_AGG
void
draw_polyline(gcid_t, const double * vertices, unsigned num_vertices);

API_AGG
void
draw_polygon(gcid_t, const double * vertices, unsigned num_vertices);

API_AGG
void
draw_circle(gcid_t, double center_x, double center_y, double radius);

API_AGG
void
draw_point(gcid_t, double x, double y);

API_AGG
void
draw_line(gcid_t, double x1, double y1, double x2, double y2);

/* TODO Path building interface (see Postscritp)

    newpath
    moveto...
    closepath
*/

API_AGG
void
new_path(gcid_t);

API_AGG
void
draw_path(gcid_t);

API_AGG
void
moveto(gcid_t, double, double);

API_AGG
void
rmoveto(gcid_t, double x, double y);

API_AGG
void
lineto(gcid_t, double, double);

API_AGG
void
rlineto(gcid_t, double, double);

API_AGG
void
hlineto(gcid_t, double);

API_AGG
void
rhlineto(gcid_t, double);

API_AGG
void
vlineto(gcid_t, double);

API_AGG
void
rvlineto(gcid_t, double);

API_AGG
void
close_polygon(gcid_t);

API_AGG
void
gc_set_property(gcid_t, int property, double value);

API_AGG
void
gc_swap_coord(gcid_t, int);

API_AGG
int
gc_set_font(gcid_t, const uint8 * font_name_utf8, unsigned nbytes);

API_AGG
void
gc_set_font_size(gcid_t id, double x);

API_AGG
void
draw_text(gcid_t, const uint8 * text_utf8, unsigned nbytes, double x, double y);


// VERTICES         array of vertices for all polygons, size is sum of all
//                  counts in VERTEX_COUNTS times two
// VERTEX_COUNTS    array of number of vertices for each polygon, size is NUM_POLYGONS
// NUM_POLYGONS     number of polygons
// COLORS           array of colors, size is NUM_POLYGONS
API_AGG
void
draw_compound_polygon_solid(gcid_t              id,
                            const double *      vertices, 
                            const unsigned *    vertex_counts,
                            unsigned            num_polygons, 
                            const uint32 *      colors);

EXTERNC_END


#endif /* AGG_API_H_INCLUDED */
