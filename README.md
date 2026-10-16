# diffusion-
Basic solution of differential equation for diffusion in 1D

## gnu plot commands for plotting the output data
```c
#gif 

set terminal gif animate delay 30 size 800,600 # animate delay _ adjust delay between frames
set output "Flip.gif" #name
set xlabel "i"
set ylabel "t"
set title "Distribution Evolution Over Time - FLip" #label
set yrange [-1:1] #edit plotrange as needed 
set grid

do for [iter=0:40] {
    plot "diffusion.dat" every :::iter::iter using 1:2 with linespoints lw 3 \
         title sprintf("Iteration %d", iter)
}
set output
_______________________________________________________________________________________________________________
# Basic graph plot
set terminal pngcairo size 1000,700 enhanced font "Arial,12"
set output "plot_whole_lot2.png" # name

set xlabel "i"
set ylabel "t"
set title "Distribution Evolution - Whole lot " # label
set grid
set yrange [-1:1] #edit range for each plot
set style data linespoints
set pointsize 0.8
set key off  #remove this to show itteration number 

# Plot all iterations on one graph
plot for [iter=0:99] "diffusion.dat" every :::iter::iter using 1:2 with linespoints \
     lw 2 ps 1 title sprintf("Iteration %d", iter)



