#include <stdlib.h>
#include "gnuplot.h"
// Function to generate random values within the range
void generate_random_values(double *data, int size, double max_value)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = (double)rand() / RAND_MAX * max_value;
    }
}
int main()
{

    // 2D line figure

    int n = 10;

    // Example with integer x and integer y
    int x_int[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int y_int[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    plot_2Dline_graph(x_int, y_int, n, "Integer X and Y Plot", "X-Axis", "Y-Axis", 1, 1, "plot1.png", "legend1");

    // Example with double x and integer y
    double x_double[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
    plot_2Dline_graph(x_double, y_int, n, "Double X, Integer Y Plot", "X-Axis", "Y-Axis", 0, 1, "plot2.png", "legend1");

    // Example with integer x and double y
    double y_double[10] = {2.3, 3.1, 4.7, 5.5, 6.2, 7.8, 8.0, 9.5, 10.1, 11.0};
    plot_2Dline_graph(x_int, y_double, n, "Integer X, Double Y Plot", "X-Axis", "Y-Axis", 1, 0, "plot3.png", "legend1");

    // Example with double x and double y
    plot_2Dline_graph(x_double, y_double, n, "Double X and Y Plot", "X-Axis", "Y-Axis", 0, 0, "plot4.png", "legend1");

    // // Histogram :
    // int num_values = 1000;    // Number of values to analyze
    // double max_value = 100.0; // Maximum range value
    // double min_value = 0.0;   // Maximum range value
    // int num_bins = 10;        // Number of bins
    // double data[num_values];
    // int *bins;

    // // Generate random data
    // generate_random_values(data, num_values, max_value);

    // int max_bin_count = compute_distribution_double(data, num_values, &bins, num_bins, max_value, min_value);

    // int data[] = {10, 15, 22, 35, 42, 48, 55, 60, 67, 72, 80, 85, 90, 95};
    int data[20] = {
        3, 2, 5, 1, 6, 4, 3, 2, 5, 1, 6, 3, 4, 2, 5, 6, 1, 3, 4, 2};
    int size = sizeof(data) / sizeof(data[0]);

    int *bins;
    int num_bins = 6;
    int min_value = 1, max_value = 6;

    int max_bin_count = compute_distribution_int(data, size, &bins, num_bins, max_value, min_value);

    // save histogeram
    plot_histogram(bins, num_bins, max_value, size, "data.dat", "Histogram Title", "bins", "frequency", "histogram.png", "data_legend", max_bin_count);

    free(bins);
    return 0;
}