import tkinter as tk
import math

class LabWorkApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Лабораторная работа №7")
        self.root.geometry("600x600")

        self.canvas = tk.Canvas(self.root, width=600, height=600, bg='white')
        self.canvas.pack()

        self.angle = 0
        self.radius = 3  # Измененный размер для уменьшения снежинки
        self.center = (300, 300)

        self.timer()
        self.draw_text()

    def timer(self):
        self.update_animation()
        self.draw_figure()
        self.root.after(100, self.timer)

    def update_animation(self):
        self.angle += 10
        self.radius += 1

    def draw_text(self):
        text = "Графические примитивы в библиотеке QT"
        x, y = 10, 10

        for char in text:
            self.canvas.create_text(x, y, text=char, font=("Gothic", 11), anchor="nw")
            y += 15  # Изменение координат для вертикального вывода

    def draw_figure(self):
        self.canvas.delete("figure")

        num_lines = 12  # Количество лучей снежинки
        angle_step = 360 / num_lines

        for i in range(num_lines):
            start_point = self.calculate_point(i * angle_step)
            end_point = self.calculate_point((i + 6) * angle_step)
            color = '#%02x%02x%02x' % (255, int(i * (255 / num_lines)), 255)
            self.canvas.create_line(start_point, end_point, fill=color, tags="figure")

    def calculate_point(self, angle):
        x = self.center[0] + self.radius * 8 * math.sin(angle * math.pi / 180.0)
        y = self.center[1] + self.radius * 8 * math.cos(angle * math.pi / 180.0)
        return x, y

if __name__ == "__main__":
    root = tk.Tk()
    app = LabWorkApp(root)
    root.mainloop()
