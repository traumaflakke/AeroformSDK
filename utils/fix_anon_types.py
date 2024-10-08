import re


def fix_xplane_types(input_file, output_file):
    with open(input_file, "r") as f:
        content = f.read()

    # Удаление упоминаний о "unnamed enum"
    content = re.sub(r"typedef enum \(unnamed enum at [^)]+\)", "typedef enum", content)

    # Удаление упоминаний о "unnamed struct"
    content = re.sub(
        r"typedef struct \(unnamed struct at [^)]+\)", "typedef struct", content
    )

    with open(output_file, "w") as f:
        f.write(content)


if __name__ == "__main__":
    fix_xplane_types("xplane_types.h", "xplane_types_fixed.h")
