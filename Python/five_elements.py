"""
    This program take integers from the user. Then print the sum
    of each five numbers. The remainder remember in the list buf.
"""

class Buffer:
    """This class have two method and one list"""

    def __init__(self):
        # In this list write the remainder.
        self.buf = []

    def add(self, *a):
        # Write integers from the user to the buf
        self.buf.extend(a)

        # if the number of the integer more then 4
        while len(self.buf) > 4:
            # printing the first five element of the buf
            print(sum(self.buf[0:5]))
            # delete the first five element of the buf
            self.buf = self.buf[5:]

    def get_current_part(self):
        # return remainder in the buf
        return self.buf


buf = Buffer()
buf.add(1, 2, 3)
buf.get_current_part()
buf.add(4, 5, 6)
buf.get_current_part()
buf.add(7, 8, 9, 10)
buf.get_current_part()
