#include <stdio.h>
#include <stdlib.h>

void plot_2Dline_graph(const void *x, const void *y, int n, 
                const char *title, const char *xlabel, const char *ylabel, 
                int is_int_x, int is_int_y, const char *output_filename, const char *legend) {
    if (n <= 0) {
        fprintf(stderr, "Error: Number of points must be greater than zero.\n");
        return;
    }

    // Create a temporary file to store data
    FILE *data_file = fopen("plot_data.dat", "w");
    if (!data_file) {
        perror("Error opening data file");
        return;
    }

    // Write data points to the file
    for (int i = 0; i < n; i++) {
        double x_val = is_int_x ? ((int *)x)[i] : ((double *)x)[i];
        double y_val = is_int_y ? ((int *)y)[i] : ((double *)y)[i];
        fprintf(data_file, "%lf %lf\n", x_val, y_val);
    }
    fclose(data_file);

    // Open a pipe to Gnuplot
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (!gnuplot) {
        perror("Error opening Gnuplot");
        return;
    }

    // Send plotting commands to Gnuplot
    fprintf(gnuplot, "set terminal pngcairo enhanced font 'Arial,12' size 800,600\n"); // PNG output
    fprintf(gnuplot, "set output '%s'\n", output_filename);
    fprintf(gnuplot, "set title \"%s\"\n", title);
    fprintf(gnuplot, "set xlabel \"%s\"\n", xlabel);
    fprintf(gnuplot, "set ylabel \"%s\"\n", ylabel);
    fprintf(gnuplot, "plot \"plot_data.dat\" with linespoints title \"%s\"\n",legend);

    // Close the pipe
    pclose(gnuplot);

    printf("Plot saved as %s\n", output_filename);
}