#ifndef GNUPLOT_H
#define GNUPLOT_H
    void plot_2Dline_graph(const void *x, const void *y, int n, 
                const char *title, const char *xlabel, const char *ylabel, 
                int is_int_x, int is_int_y, const char *output_filename, const char *legend);
#endif