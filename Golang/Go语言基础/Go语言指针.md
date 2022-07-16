# Go语言指针

### 指针的定义

```go
//指针定义
var a int =2
var pa *int=&a
*pa=3
fmt.Println(a)
```

### 参数传递

Go语言只有值传递一种方式，但是可以配合指针进行引用传递，自定义类型可以先进行考虑，是进行引用传递还是值传递。

```go
//main函数中的内容
a,b:=3,4
swap(&a,&b)

//函数实现
func swap(a,b *int){
	*b,*a=*a,*b
	//这里的用法和Python大同小异
}

//或者可以设计成返回值的形式即
func swap(a,b int)(int ,int ){
    return b,a
}
//在main函数中的形式
a,b:=3,4
a,b=swap(a,b)
```

