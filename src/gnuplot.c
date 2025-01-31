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
// Function to compute histogram distribution
int compute_disturbution_histogram(double *data, int size, int *bins, int num_bins, double max_value) {
    double bin_width = max_value / num_bins;
    int max_bin_count = 0;

    for (int i = 0; i < size; i++) {
        int bin_index = (int)(data[i] / bin_width);
        if (bin_index >= num_bins) bin_index = num_bins - 1;  // Edge case
        bins[bin_index]++;
        if (bins[bin_index] > max_bin_count) max_bin_count = bins[bin_index];  // Track max bin
    }

    return max_bin_count;
}
// Function to save histogram data to a file
void plot_histogram(int *bins, int num_bins, double max_value, const char *filename
                    ,const char *title, const char *xlabel, const char *ylabel 
                ,const char *output_filename, const char *legend,int max_bin_count) {
    
    // Write data points to the file
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    double bin_width = max_value / num_bins;
    for (int i = 0; i < num_bins; i++) {
        double bin_center = (i + 0.5) * bin_width;
        fprintf(file, "%lf %d\n", bin_center, bins[i]);
    }
    fclose(file);

    // Call Gnuplot to plot the data
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (!gnuplot) {
        perror("Error opening Gnuplot");
        return;
    }
    fprintf(gnuplot, "set terminal png\n");
    fprintf(gnuplot, "set output '%s'\n",output_filename);
    fprintf(gnuplot, "set title '%s'\n",title);
    fprintf(gnuplot, "set xlabel '%s'\n",xlabel);
    fprintf(gnuplot, "set ylabel '%s'\n",ylabel);
    fprintf(gnuplot, "set yrange [0:%d]\n", (int)(max_bin_count * 1.2)); // Adjust Y range dynamically
    fprintf(gnuplot, "set boxwidth 0.8 relative\n");
    fprintf(gnuplot, "set style fill solid\n");
    fprintf(gnuplot, "plot '%s' using 1:2 with boxes title '%s'\n",filename,legend);
    

    printf("Plot saved as %s\n", output_filename);
    pclose(gnuplot);
    
}