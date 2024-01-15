import png
import sys


def process(filename):
    width, height, rowgen, info = png.Reader(filename=filename).read()

    if height % 8 != 0 or info["bitdepth"] != 1:
        return

    invert = sum(info["palette"][0]) > sum(info["palette"][1])
    rows = list(rowgen)
    outlist = []

    for page_offset in range(0, height, 8):
        for col in range(width):
            val = 0
            for page_row in range(8):
                if rows[page_offset + page_row][col] > 0:
                    val |= 1 << page_row
            if invert:
                val = ~val
            outlist.append(val & 0xff)

    vals_per_line = 20
    while vals_per_line > 1:
        if width % vals_per_line == 0:
            break
        vals_per_line -= 1

    outstr = "{\n    "
    for line_offset in range(0, len(outlist), vals_per_line):
        for index in range(line_offset, line_offset + vals_per_line):
            outstr += f"{outlist[index]:#04x}, "
        outstr = outstr[:-1] + "\n"
        if (line_offset + vals_per_line) % width == 0:
            outstr += "\n"
        outstr += "    "
    outstr = outstr[:-7] + "\n}"

    return outstr


print(process(sys.argv[1]))
