import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

import os
if not os.path.exists('memread.log'):
    print("memread.log not found")
    exit(1)

# 1. Load data
df = pd.read_csv('memread.log', sep='\\s+', names=['time', 'addr_hex'], dtype={'time': int, 'addr_hex': str})
df['addr'] = df['addr_hex'].apply(lambda x: int(x, 16))

# 2. Temporal Locality: Reuse Distance
# For each address, find the time difference between consecutive accesses
df = df.sort_values('time')
df['reuse_dist'] = df.groupby('addr')['time'].diff()
reuse_distances = df['reuse_dist'].dropna()

# 3. Spatial Locality: Address Distance between consecutive accesses
# delta_addr = |addr_next - addr_current|
df['spatial_dist'] = (df['addr'].shift(-1) - df['addr']).abs()
spatial_distances = df['spatial_dist'].dropna()

# Plotting
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 10))

# Reuse Distance Plot
if not reuse_distances.empty:
    ax1.hist(reuse_distances, bins=30, color='skyblue', edgecolor='black')
    ax1.set_title('Distribution of Reuse Distances (Temporal Locality)')
    ax1.set_xlabel('Time Delta (units)')
    ax1.set_ylabel('Frequency')
else:
    ax1.text(0.5, 0.5, 'No repeated addresses found for Reuse Distance', ha='center')

# Spatial Distance Plot
if not spatial_distances.empty:
    # We focus on small distances to see locality
    # Filter out very large jumps if necessary, or use log scale
    ax2.hist(spatial_distances, bins=50, color='salmon', edgecolor='black')
    ax2.set_title('Distribution of Address Distances (Spatial Locality)')
    ax2.set_xlabel('Address Delta (bytes)')
    ax2.set_ylabel('Frequency')
    ax2.set_yscale('log') # Log scale helps see small frequencies
else:
    ax2.text(0.5, 0.5, 'Insufficient data for Spatial Locality', ha='center')

plt.tight_layout()
plt.savefig('locality_analysis.png')

print("Analysis complete.")
print(f"Mean Reuse Distance: {reuse_distances.mean():.2f}" if not reuse_distances.empty else "No reuse found.")
print(f"Mean Spatial Distance: {spatial_distances.mean():.2f}" if not spatial_distances.empty else "No spatial data.")
