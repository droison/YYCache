fork的YYCache，但YYCache在处理大文件disk存储不够方便，做了一些外科手术式的微调

个人针对YYCache的修改，主要处理大文件load到内存的问题，大文件只以地址的形式返回，源代码请参考 https://github.com/ibireme/YYCache
