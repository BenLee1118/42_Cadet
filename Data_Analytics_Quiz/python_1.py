import pandas as pd
import matplotlib
from matplotlib import pyplot as plt
matplotlib.rcParams['figure.figsize'] = (10, 6)

df = pd.read_csv("weight-height.csv")

# Display the first 5 rows of the DataFrame
examples = df.head(5)
print(f"\n##### Check First 5 Data #####")
print(f"{examples}\n")

# Create a histogram of the 'Height' column
plt.hist(df.Height, bins=20, rwidth=0.8)
plt.xlabel('Height (inches)')
plt.ylabel('Count')

# Save the plot as an image (e.g., PNG)
plt.savefig("histogram.png")
print(f"!!! Count-Height Histrogram Created !!!\n")

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
print(f"!!! Count-Height Line Histrogram Created !!!\n")

# Display all the necessary data
print(f"### Print All Necessary Infos ###")
infos = df.Height.describe()
print(f"{infos}\n")

# Show the mean and standard deviation
meann = df.Height.mean()
stddev = df.Height.std()
print(f"	########## Mean & Standard Deviation ##########")
print(f"Mean = {meann}		Standard Deviation = {stddev}\n")

### Outlier Detection Method 1 using standard deviation ###
upper_limit = df.Height.mean() + 3*df.Height.std()
lower_limit = df.Height.mean() - 3*df.Height.std()
print(f"###*** Outlier Detection Method 1 using Standard Deviation ***###")
print(f"		########## Limitations ##########")
print(f"Upper Limit = {upper_limit}		Lower Limit = {lower_limit}\n")

# Print the outliers
outliers = df[(df.Height>upper_limit) | (df.Height<lower_limit)]
print(f"   ### Outliers are below ###")
print(f"{outliers}\n")


### Outlier Detection Method 2 using Percentile ###
print(f"###*** Outlier Detection Method 2 using Percentile ***###")
print(f"### Print Again Necessary Infos ###")
infos_2 = df['Height'].describe()
print(f"{infos_2}\n")

import seaborn as sns
import warnings
warnings.filterwarnings("ignore")
sns.distplot(df['Height'])
plt.savefig("percentile_distribution.png")
print(f"!!! Percentile Distribution Created !!!\n")

# Create a seaborn box plot and save it as "seaborn_boxplot.png"
sns.boxplot(df['Height'])
plt.savefig("percentile_boxplot.png")
print(f"!!! Percentile Boxplot Created !!!\n")

# Finding Upper and Lower Limit
upper_limit_2 = df['Height'].quantile(0.99)    #means any value over 99 percentile is an outlier    
lower_limit_2 = df['Height'].quantile(0.01)      #means any value below 1 percentile is an outlier
print(f"		########## Limitations ##########")
print(f"Upper Limit = {upper_limit_2}		Lower Limit = {lower_limit_2}\n")

#Print the outliers
outliers_2 = df[(df['Height'] >= 74.78) | (df['Height'] <= 58.13)]
print(f"   ### Outliers are below ###")
print(f"{outliers_2}\n")