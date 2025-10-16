import numpy as np
import pandas as pd
from sklearn.cluster import KMeans

# Data from your table
data = {
    'Height': [185, 170, 168, 179, 182, 188, 180, 180, 183, 180, 180, 177],
    'Weight': [72, 56, 60, 68, 72, 77, 71, 70, 84, 88, 67, 76],
}
df = pd.DataFrame(data)

# Prepare feature matrix
X = df[['Height', 'Weight']]

# Set initial centroids manually
init_centroids = np.array([[185, 72], [170, 56]])

# Run KMeans with manual centroids and 2 clusters
kmeans = KMeans(n_clusters=2, init=init_centroids, n_init=1, random_state=42)
kmeans.fit(X)

# Create cluster labels: K1 or K2
labels = ['K1' if label == 0 else 'K2' for label in kmeans.labels_]
df['Cluster'] = labels

print(df)
print("Cluster centers:", kmeans.cluster_centers_)
