import numpy as np
import matplotlib.pyplot as plt

# Load data
data = np.loadtxt('build/output.txt', delimiter='\t', skiprows=1)

eS1 = data[:,0]
eS2 = data[:,1]
eS3 = data[:,2]
eS4 = data[:,3]

# Plot
fig, axes = plt.subplots(2, 2, figsize=(10, 8))
fig.suptitle('Muon Energy Deposit in Scintillator Panels\nGeant4 Simulation of IIT Kanpur Muon Telescope (arXiv:2602.16297)', fontsize=12)

panels = [eS1, eS2, eS3, eS4]
names  = ['S1 (Active)', 'S2 (Active)', 'S3 (Passive - no MPPC)', 'S4 (Active)']
colors = ['steelblue', 'seagreen', 'grey', 'tomato']

for i, ax in enumerate(axes.flat):
    ax.hist(panels[i], bins=100, range=(0, 15), color=colors[i], alpha=0.7, edgecolor='black', linewidth=0.3)
    mean_val = np.mean(panels[i])
    ax.axvline(mean_val, color='black', linestyle='--', linewidth=1.5, label=f'Mean = {mean_val:.2f} MeV')
    ax.set_xlabel('Energy Deposit (MeV)', fontsize=11)
    ax.set_ylabel('Counts', fontsize=11)
    ax.set_title(names[i], fontsize=11)
    ax.legend(fontsize=10)
    ax.grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig('mip_peak.png', dpi=150, bbox_inches='tight')
print("Plot saved as mip_peak.png")
print("\nMean energy deposits:")
print(f"  S1: {np.mean(eS1):.3f} MeV")
print(f"  S2: {np.mean(eS2):.3f} MeV")
print(f"  S3: {np.mean(eS3):.3f} MeV")
print(f"  S4: {np.mean(eS4):.3f} MeV")
print(f"\nBethe-Bloch MIP approximation: {2 * 1.032 * 1.28:.3f} MeV")
print(f"Number of coincidence events: {len(eS1)}")
