# A simple obj converter for the BWM model format

import argparse
import struct
from os.path import exists
import os

def pack_number(num):
    int_to_four_bytes = struct.Struct('>I').pack
    return int_to_four_bytes(num & 0xFFFFFFFF)


if __name__ == '__main__':
    
    parser = argparse.ArgumentParser()
    parser.add_argument("input_file", help="Input OBJ file")
    parser.add_argument("output_file", help="Output BWM file")
    parser.add_argument("texture_size", help="Specifies the size of the texture (X by X)")
    args = parser.parse_args()
    
    try:
        obj_file = open(args.input_file, "r")
    except:
        print("Failed to open the input file:", args.input_file)
        exit()
    try:
        if not args.output_file.endswith(".bwm"):
            args.output_file = args.output_file + ".bwm"
        if exists(args.output_file):
            print("The output file already exists. Would you like to overwrite it? [Y/n]")
            reply = input().lower().strip()
            if reply == "y" or len(reply) == 0:
                os.remove(args.output_file)
            else:
                exit()
        bwm_file = open(args.output_file, "wb")
    except Exception as e:
        obj_file.close()
        print("Failed to open the output file:", args.output_file)
        print(e)
        exit()

    vertices = []
    vertex_indices = []

    uvs = []
    uv_indices = []

    normals = []
    normal_indices = []

    num_faces = 0
    
    for line in obj_file:
        data = line.split(" ")
        operation = data[0]

        if operation == "v":
            x = int(float(data[1]))
            y = int(float(data[2]))
            z = int(float(data[3]))
            
            vertices.append([x,y,z])
        
        elif operation == "vt":
            u = int(float(data[1])*int(args.texture_size))-1
            v = int(float(data[2])*int(args.texture_size))-1

            if(u < 0):
                u = 0
            if(v < 0):
                v = 0
            
            uvs.append([u,v])
        
        elif operation == "vn":
            x = int(float(data[1]))
            y = int(float(data[2]))
            z = int(float(data[3]))
            
            normals.append([x,y,z])
        elif operation == "f":
            v0 = data[1].split("/")
            v1 = data[2].split("/")
            v2 = data[3].split("/")
            v3 = data[4].split("/")

            vi_0 = int(v0[0])
            vi_1 = int(v1[0])
            vi_2 = int(v2[0])
            vi_3 = int(v3[0])
            
            
            ui_0 = int(v0[1])
            ui_1 = int(v1[1])
            ui_2 = int(v2[1])
            ui_3 = int(v3[1])
            
            ni_0 = int(v0[2])
            ni_1 = int(v1[2])
            ni_2 = int(v2[2])
            ni_3 = int(v3[2])

            uv_indices.append([ui_0, ui_1, ui_3, ui_2])
            vertex_indices.append([vi_0, vi_1, vi_3, vi_2])
            normal_indices.append([ni_0, ni_1, ni_3, ni_2])
            num_faces += 1
    bwm_file.write(pack_number(num_faces))
    
    bwm_file.write(pack_number(len(vertices)))
    for vertex in vertices:
        for coord in vertex:
            bwm_file.write(pack_number(coord))
    

    bwm_file.write(pack_number(len(vertex_indices)))
    for face in vertex_indices:
        for indice in face:
            bwm_file.write(pack_number(indice))

    bwm_file.write(pack_number(len(uvs)))
    for uv in uvs:
        for coord in uv:
            bwm_file.write(pack_number(coord))
    
    bwm_file.write(pack_number(len(uv_indices)))
    for face in uv_indices:
        for indice in face:
            bwm_file.write(pack_number(indice))
    
    bwm_file.write(pack_number(len(normals)))
    for normal in normals:
        for coord in normal:
            bwm_file.write(pack_number(coord))

    bwm_file.write(pack_number(len(normal_indices)))
    for face in normal_indices:
        for indice in face:
            bwm_file.write(pack_number(indice))
    bwm_file.close()
    print("The file:",args.output_file, "was successfully written")
    print("Vertex count:", len(vertices))
    print("Vertex indices count:", len(vertex_indices))
    print("UV count:", len(uvs))
    print("UV indices count:", len(uv_indices))
    print("Normal count:", len(normals))
    print("Normal indices count:", len(normal_indices))

    print(normal_indices)
