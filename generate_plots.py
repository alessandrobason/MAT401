import pandas as pd
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np

f64 = np.float64

def plot_task_2():
    data = pd.read_csv(
        "results/task_2.csv", 
        dtype = { "time": f64, "x": f64, "y": f64, "z": f64 }
    )

    time = data["time"].values

    plt.plot(time, data["x"].values, label="x")
    plt.plot(time, data["y"].values, label="y")
    plt.plot(time, data["z"].values, label="z")

    plt.xlabel("Time (seconds)")
    plt.ylabel("Angular Velocity (1 / radians)")
    plt.title("Task 2")

    plt.legend()
    plt.savefig("results/task_2.png", dpi=300)
    plt.close()

def plot_task_4():
    data = pd.read_csv(
        "results/task_4.csv",
        dtype = { "time": f64, "vx": f64, "vy": f64, "vz": f64, "px": f64, "py": f64, "pz": f64 }
    )

    time = data["time"].values

    # Velocity

    plt.plot(time, data["vx"].values, label="vx")
    plt.plot(time, data["vy"].values, label="vy")
    plt.plot(time, data["vz"].values, label="vz")

    plt.xlabel("Time (seconds)")
    plt.ylabel("Velocity (meters / seconds)")
    plt.title("Task 4 - Velocity")

    plt.legend()
    plt.savefig("results/task_4-velocity.png", dpi=300)
    plt.close()

    # Displacement

    plt.plot(time, data["px"].values, label="x")
    plt.plot(time, data["py"].values, label="y")
    plt.plot(time, data["pz"].values, label="z")

    plt.xlabel("Time (seconds)")
    plt.ylabel("Displacement (meters)")
    plt.title("Task 4 - Displacement")

    plt.legend()
    plt.savefig("results/task_4-displacement.png", dpi=300)
    plt.close()

def plot_task_5():
    data = pd.read_csv(
        "results/task_5.csv",
        dtype = { "x": f64, "y": f64 }
    )

    plt.plot(data["y"].values, data["x"].values, label="position")

    plt.xlabel("X (meters)")
    plt.ylabel("Y (meters)")
    plt.title("Task 5")

    plt.legend()
    plt.savefig("results/task_5.png", dpi=300)

    plt.close()

plot_task_2()
plot_task_4()
plot_task_5()
