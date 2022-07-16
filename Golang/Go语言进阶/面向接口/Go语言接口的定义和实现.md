# Go语言接口的定义和实现以及接口对象的内容

## 一、接口的定义

接口由使用者来实现：

​		使用者也就是我们所说的使用接口的类，go语言中只需要给出接口，以及其中的方法即可，不需要在调用它的类中显式声明其使用了当前的接口，我们有以下的方法创建一个接口：

```go
type Retriever interface {
   Get(url string) string
}
```

​		然后利用接口定义了一个方法

```go
func download(r Retriever) string {
   return r.Get("https://www.imooc.com")
}
```

​		我们参数是Retriever，我们需要有一个同类的对象才能调用这个值，这样我们在main中创建一个接口对象

```go
var p Retriever
```

​		我们此时的项目结构如下：

![image-20220711225114499](Images/image-20220711225114499.png)

​	我们在mock和real下都定义了Retriever类

​	**mock**

```go
package mock

type Retriever struct {
   Contents string
}

func (r Retriever) Get(url string) string { //这里是实现了get方法，但是咱们没有显式声明说我们调用了这个接口
   return r.Contents
}
```

​	**real**

```go
package real

import (
   "net/http"
   "net/http/httputil"
   "time"
)

type Retriever struct {
   UserAgent string
   Timeout   time.Duration
}

func (r Retriever) Get(url string) string {
   resp, err := http.Get(url)
   if err != nil {
      panic(err)
   }
   result, err := httputil.DumpResponse(resp, true)
   resp.Body.Close()
   if err != nil {
      panic(err)
   }
   return string(result)
}
```

​	我们在main函数中让p指向real中的类对象

```go
p = real.Retriever{}
```

​	这样我们可以通过p调用然后打印出来内容，如下：

```go
fmt.Println(download(p))
```

​	这样我们就实现了接口的定义与调用

## 二、接口对象的内容

我们在上述的调用中，创建了一个接口的实例对象为p，那么p中的内容又是什么呢？

我们用下面一段代码

```go
func main() {
   var p Retriever
   p = real.Retriever{}
   fmt.Printf("%T,%v", p, p)
}
```

这样我们得到p的结果为

![image-20220711230109902](Images/image-20220711230109902.png)

也就是p作为一个指针，指向了调用其类的对象，由于go语言全都是值传递，我们也就可以知道这里面存储的是其类型和值，但是有一个问题，我们如果是通过指针来访问这个get呢？

我们将real中的Retriever中的get改为

```go
func (r *Retriever) Get(url string) string {
   resp, err := http.Get(url)
   if err != nil {
      panic(err)
   }
   result, err := httputil.DumpResponse(resp, true)
   resp.Body.Close()
   if err != nil {
      panic(err)
   }
   return string(result)
}
```

我们看一下，这样的情况，我们会发现p应该指向

```go
p = &real.Retriever{}
```

也就是说我们所谓的接口的实例对象，应该指向调用接口中函数的对象类型。

## 三、利用接口对象中的指向的类的内容进行一些操作

### 1.利用switch判断指向的类型

这里我们利用switch判断p指向的类型，然后进行操作

```go
switch v := p.(type) {
case mock.Retriever:
   fmt.Println("Contents:", v.Contents)
case *real.Retriever:
   fmt.Println("UserAgent:", v.UserAgent)
}
```

### 2.得到其中的值

![image-20220711232304443](Images/image-20220711232304443.png)

这里我们利用了if语句，打印了当是指向mockRetriever时的情况

## 四、总结

接口变量里面有什么

![image-20220711232456940](Images/image-20220711232456940.png)

- 接口变量自带指针
- 接口变量同样采用值传递，几乎不需要使用接口的指针
- **指针接收者实现只能以指针方式使用，值接收者都可以**



### **特殊用法补充：**

利用interface{}作为函数参数，则代表参数可以为任何类型

![image-20220711233041483](Images/image-20220711233041483.png)

![image-20220711232928828](Images/image-20220711232928828.png)

以我们前面实现的队列为例，原本我们是只能压入整数，这样我们可以压入任何值，那我们要是原本的类型为interface{}，但是返回值和调用又想约束成为int，这样我们可以以下面的方式实现

![image-20220711233133023](Images/image-20220711233133023.png)

返回值为int时，则加入.(int)则实现