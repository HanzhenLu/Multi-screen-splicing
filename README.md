# 多屏幕拼接
浙江大学(ZJU)计算机图形学(Computer Graphics)作业,  
## 简介
how to stick 2 * 2 virtual screen together to create a larger OpenGL viewport  
只要了解`glFrustum`和`glViewport`这两个函数就能很快做出结果，不了解的话像我一样一个个参数慢慢调，花一个晚上也能装运气试出来  
## 最终效果
正交投影  
![image-20221117215906853](https://user-images.githubusercontent.com/110232285/204294331-53674e0e-0892-4e06-9a32-74861b9513b2.png)
透视投影  
![image-20221117215934590](https://user-images.githubusercontent.com/110232285/204294709-efdd9072-f694-43d9-9642-986ce2106afe.png)
![image-20221117220016025](https://user-images.githubusercontent.com/110232285/204294397-bc25978d-622a-498f-a17d-2beb0906315d.png)
不绘制左下角的屏幕  
![image-20221117220125103](https://user-images.githubusercontent.com/110232285/204294534-8972478a-fdc8-4303-aa7f-5e7b1cf1ba7f.png)
![image-20221117220144544](https://user-images.githubusercontent.com/110232285/204294555-ab819ba8-320a-4c01-a4a7-c04bb879081e.png)
