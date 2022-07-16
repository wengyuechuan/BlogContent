# Go语言的变量

一、变量类型

1.bool,string 布尔值，字符串类型

2.(u)int,(u)int8,(u)int32,(u)int64,uintptr 整型

3.byte 8位字符 rune32位字符

4.float32,float64,complex64,complex128 浮点数和复数

二、验证欧拉公式

![image-20220702005300662](C:\Users\wengy\AppData\Roaming\Typora\typora-user-images\image-20220702005300662.png)

利用go语言的复数运算，对欧拉公式进行验证

```go
第一个是使用的cmplx.Pow进行
第二个是利用Exp进行运算
func euler() {
	cmplx.Pow(math.E, 1i*math.Pi)
}
func euler1() {
	fmt.Printf("%.3f\n", cmplx.Exp(1i*math.Pi)+1)
}
```

三、类型转换

go语言类型转换是必须使用强制的，也就是必须加上int()注意这里的使用

```go
var c int
c = int(math.Sqrt(float64(3*3 + 4*4)))
```

四、常量的定义

```go
const(
filename="abc.txt"
a,b=3,4
)
```

由于go语言没有枚举类型，则我们可以使用const来解决这个问题

```go
const(
cpp=0
python=1
golang=2
)
```

当然也提供了一个自动迭代的一个值，使用方法如下

```go
const(
cpp=iota
python
java
javascript
)
```

iota也有更加高级的应用

```go
const(
b=iota*10
python
java
javascript
)
```

则这里意味着可以利用迭代器进行更多的操作，然后进行赋值