# BWM format
The BWM *(Bandwidth model)* format was created for my horror game for the PSX which I'm recording a video series about on YouTube. It's currently very memory inefficient and has only very basic features.

## Features
The file format can now store the following:
- Vertex coordinates
- UV coordinates
- Normal vectors

All of the data is indexed in order to save space by reusing vertex, uv and normal data.

## File format
Unlike responsible file formats this one doesn't have a header. It stores data in the following way:

All values are signed 32bit integers each split into 4 bytes. (DWORD) Meaning the final size is always a multiple of 4 therefore the file is 4-byte aligned.

The data is stored in the file in the following order:
```
Size (in DWORDs)    Meaning

[1]                 Number of faces - f_count
[1]                 Number of vertices - v_count
[v_count]           Vertex coordinates (3 DWORDs each)
[1]                 Number of vertex indices - vi_count
[vi_count]          Vertex indices
[1]                 UVs count - uv_count 
[uv_count]          UV coordinates      
[1]                 Number of uv indices - uvi_count
[uvi_count]         UV indices   
[1]                 Normals count - n_count 
[n_count]           Normal coordinates      
[1]                 Number of normal indices - ni_count
[ni_count]          Normal indices  
```

## TODO
- This format really needs a header. Especially considering the fact that there's going to be a future version which will break existing parsers.
- Store space by storing 2 16-bit numbers into a DWORD to save space.