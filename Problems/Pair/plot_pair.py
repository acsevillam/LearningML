import pandas as pd
import datashader as ds
from datashader.colors import inferno, viridis

data=pd.read_csv('data.dat',sep=' ',header=None).dropna(axis=1)
data["p"]=(data[1]+data[3])/2
data["q"]=(data[0]+data[2])/2


cvs = ds.Canvas(plot_width=700, plot_height = 600)
agg = cvs.points(data,'q','p')
ds.transfer_functions.shade(agg, cmap =viridis)
