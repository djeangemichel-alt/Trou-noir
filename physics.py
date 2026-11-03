import numpy as np

import numpy as np

G = 0.1

class Body:
    def __init__(self, x, y, vx, vy, mass):
        self.pos = np.array([x, y], dtype=float)
        self.vel = np.array([vx, vy], dtype=float)
        self.mass = mass

    def update(self, bodies):
        force = np.array([0.0, 0.0])

        for body in bodies:
            if body != self: # une maniere de dit si l'objet est diff de lui meme
                diff = body.pos - self.pos
                distance = np.linalg.norm(diff) + 1e-5
                f = G * self.mass * body.mass / distance**2
                force += f * diff / distance

        acc = force / self.mass
        self.vel += acc
        self.pos += self.vel
    
    