import pandas as pd
import matplotlib
from matplotlib import pyplot as plt
matplotlib.rcParams['figure.figsize'] = (10, 6)

df = pd.read_csv("weight-height.csv")

# Display the first 5 rows of the DataFrame
print(df.head(5))

# Create a histogram of the 'Height' column
plt.hist(df.Height, bins=20, rwidth=0.8)
plt.xlabel('Height (inches)')
plt.ylabel('Count')

# Save the plot as an image (e.g., PNG)
plt.savefig("histogram.png")

# Create a new figure and axis for the second plot
fig, ax = plt.subplots()

# Create the second histogram of the 'Height' column
ax.hist(df.Height, bins=20, rwidth=0.8, density=True)
ax.set_xlabel('Height (inches)')
ax.set_ylabel('Count')

# Calculate the PDF (Probability Density Function) using scipy's norm.pdf
from scipy.stats import norm
import numpy as np

rng = np.arange(df.Height.min(), df.Height.max(), 0.1)
ax.plot(rng, norm.pdf(rng, df.Height.mean(), df.Height.std()))

# Save the second histogram as a separate image
plt.savefig("histogram_2.png")

# Display all the necessary data
print(df.Height.describe())

# Show the mean and standard deviation
print(df.Height.mean())
print(df.Height.std())

### Outlier Detection Method 1 using standard deviation ###
upper_limit = df.Height.mean() + 3*df.Height.std()
print(upper_limit)
lower_limit = df.Height.mean() - 3*df.Height.std()
print(lower_limit)

# Print the outliers
print(df[(df.Height>upper_limit) | (df.Height<lower_limit)])


### Outlier Detection Method 1 using standard deviation ###
print(df['Height'].describe())

import seaborn as sns
import warnings
warnings.filterwarnings("ignore")
sns.distplot(df['Height'])
plt.savefig("seaborn_distribution.png")

# Create a seaborn box plot and save it as "seaborn_boxplot.png"
sns.boxplot(df['Height'])
plt.savefig("seaborn_boxplot.png")

upper_limit = df['Height'].quantile(0.99)        
#means any value over 99 percentile is an outlier
print(upper_limit)

lower_limit = df['Height'].quantile(0.01)      
#means any value below 1 percentile is an outlier
print(lower_limit)

print(df[(df['Height'] >= 74.78) | (df['Height'] <= 58.13)])