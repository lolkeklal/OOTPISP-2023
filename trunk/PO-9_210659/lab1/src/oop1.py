import tkinter as tk
from tkinter import ttk
from tkinter import filedialog

class RGBApp:
    def __init__(self, root):
        self.root = root
        self.root.title("RGB Controller")

        self.red_var = tk.IntVar()
        self.green_var = tk.IntVar()
        self.blue_var = tk.IntVar()


        self.create_widgets()

    def create_widgets(self):
        red_label = ttk.Label(self.root, text="Red:")
        red_label.grid(row=0, column=0, padx=10, pady=10)
        red_slider = ttk.Scale(self.root, from_=0, to=255, orient="horizontal", variable=self.red_var, command=self.set_color)
        red_slider.grid(row=0, column=1, padx=10, pady=10)
        red_spinbox = ttk.Spinbox(self.root, from_=0, to=255, textvariable=self.red_var, command=self.set_color)
        red_spinbox.grid(row=0, column=2, padx=10, pady=10)

        green_label = ttk.Label(self.root, text="Green:")
        green_label.grid(row=1, column=0, padx=10, pady=10)
        green_slider = ttk.Scale(self.root, from_=0, to=255, orient="horizontal", variable=self.green_var, command=self.set_color)
        green_slider.grid(row=1, column=1, padx=10, pady=10)
        green_spinbox = ttk.Spinbox(self.root, from_=0, to=255, textvariable=self.green_var, command=self.set_color)
        green_spinbox.grid(row=1, column=2, padx=10, pady=10)

        blue_label = ttk.Label(self.root, text="Blue:")
        blue_label.grid(row=2, column=0, padx=10, pady=10)
        blue_slider = ttk.Scale(self.root, from_=0, to=255, orient="horizontal", variable=self.blue_var, command=self.set_color)
        blue_slider.grid(row=2, column=1, padx=10, pady=10)
        blue_spinbox = ttk.Spinbox(self.root, from_=0, to=255, textvariable=self.blue_var, command=self.set_color)
        blue_spinbox.grid(row=2, column=2, padx=10, pady=10)

        self.text_area = tk.Text(self.root, height=5, width=30)
        self.text_area.grid(row=3, column=0, columnspan=3, padx=10, pady=10)

        open_button = ttk.Button(self.root, text="Open File", command=self.open_file)
        open_button.grid(row=4, column=0, columnspan=3, padx=10, pady=10)

    def set_color(self, event=None):

        red = self.red_var.get()
        green = self.green_var.get()
        blue = self.blue_var.get()

        color_hex = "#{:02X}{:02X}{:02X}".format(red, green, blue)
        self.text_area.configure(bg=color_hex)

    def open_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt"), ("All files", "*.*")])

        if file_path:
            with open(file_path, "r") as file:
                content = file.read()
                self.text_area.delete(1.0, tk.END)
                self.text_area.insert(tk.END, content)


if __name__ == "__main__":
    root = tk.Tk()
    app = RGBApp(root)
    root.mainloop()
