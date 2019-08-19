class Node:
    def __init__(self,content):
        self.child = None
        self.cont = content
        self.rep = ""

    def getstring(self):
        if self.child is not None:
            self.rep = "-(-("+ self.cont + ")" + ". -("+self.child.getstring() + "))"
            return self.rep
        else:
            return self.cont

    def add_child(self, child):
        self.child = child