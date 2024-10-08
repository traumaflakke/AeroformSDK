import os

# Папка с заголовочными файлами
header_dir = "../aeroform-plugin/include"
output_swig_file = "XPLM_all.i"

def process_headers(directory):
    headers = []
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".h"):
                # Получаем относительный путь к файлу
                rel_path = os.path.relpath(os.path.join(root, file), header_dir)
                headers.append(rel_path)
    return headers

# Создаем SWIG-файл
with open(output_swig_file, "w") as swig_file:
    swig_file.write("%module XPlaneWrappers\n")
    swig_file.write("%{\n")

    # Включаем все заголовочные файлы в %{} блок
    for header in process_headers(header_dir):
        swig_file.write(f'#include "{header}"\n')

    swig_file.write("%}\n")

    # Добавляем %include для каждого заголовочного файла
    for header in process_headers(header_dir):
        swig_file.write(f'%include "{header}"\n')

print(f"SWIG interface file '{output_swig_file}' generated.")
