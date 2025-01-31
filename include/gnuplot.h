#ifndef GNUPLOT_H
#define GNUPLOT_H
    void plot_2Dline_graph(const void *x, const void *y, int n, 
                const char *title, const char *xlabel, const char *ylabel, 
                int is_int_x, int is_int_y, const char *output_filename, const char *legend);
    void plot_histogram(int *bins, int num_bins, double max_value, const char *filename
                    ,const char *title, const char *xlabel, const char *ylabel 
                ,const char *output_filename, const char *legend, int max_bin_count); 
    int compute_disturbution_histogram(double *data, int size, int *bins, int num_bins, double max_value);                        
#endif