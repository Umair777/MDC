# MDC
Multiple Data Compression and Expansion Using Iterative Technique

Introduction:

Embedded devices often grapple with memory constraints, necessitating judicious data management strategies. This README elucidates an iterative technique for compressing and expanding data to optimize memory usage efficiently.

Compression Process:

Master Array Creation: Initially, a master array is constructed to encapsulate all unique characters present in the data file. For instance, if the file comprises 100 characters but only 15 are distinct, the master array would accommodate these 15 characters.

Index Assignment: Subsequently, each character within the master array is assigned a unique index. The objective is to utilize the minimum number of bits necessary for index representation. Since a character in C typically occupies 1 byte (8 bits), optimizing index representation significantly reduces memory overhead.

Mapping and Compression: During compression, every element in the data file is mapped to its corresponding index in the master array. This mapping process enables the amalgamation of index values of two characters into a single compressed byte, thereby effectively halving memory utilization. By leveraging this technique, a substantial reduction in memory footprint is achieved without compromising data fidelity.

Example:

Data to compress: "helo to linux."

Master array: "helo tinux."

Character Indexing:

h : 0000
e : 0001
l : 0010
o : 0011
t : 0101
i : 0110
n : 0111
u : 1000
x : 1001
. : 1010
Compression:

h (0000) + e (0001) → 00000001
l (0010) + o (0011) → 00100011
t (0101) + o (0011) → 01010011
...
Expansion Process:

Decompression: To expand the compressed data, each byte is retrieved sequentially. The byte is then disassembled into its constituent upper and lower nibbles to identify the corresponding characters using the indexes from the master array.

Character Retrieval: The upper and lower nibbles extracted from the compressed byte are matched against the indexes of the master array. This matching process facilitates the reconstruction of the original characters, ensuring data integrity is maintained throughout the expansion process.

Uncompressed File Creation: Upon character reconstruction, the uncompressed data is synthesized and stored in a separate file. This file serves as the uncompressed counterpart of the original data, facilitating seamless access and utilization.

Example:

Compressed Byte: 00000001

Retrieve upper nibble: 0000 → Index of 'h'
Retrieve lower nibble: 0001 → Index of 'e'
Conclusion:

By implementing this iterative compression and expansion technique, substantial memory savings can be realized without sacrificing data integrity. The method enables the efficient utilization of storage devices with limited capacity, empowering embedded systems to accommodate larger datasets within constrained memory environments.

This comprehensive approach to data compression and expansion provides a robust framework for optimizing memory utilization in embedded systems. Feel free to integrate and adapt this technique into your projects, ensuring efficient data management and resource optimization. For further inquiries or assistance, please don't hesitate to reach out.
