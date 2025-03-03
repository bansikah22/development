### A bean
- A bean is just a java object that is managed by spring boot
- A bean is an object that is instantiated, assembled, and otherwise managed by a Spring IoC container.
- These beans are created with the configuration metadata that you supply to the container, for example, in the form of XML <bean/> definitions.

### How to create beans
- By using the @Component annotation
- By using the @Bean annotation
- By using the @Service annotation
- By using the @Repository annotation
- By using the @Controller annotation


### Accessing beans through actuators
- By using the localhost/8080/actuator/beans endpoint
- By using the /beans/{beanName} endpoint
```plaintext
localhost:8080/actuator/beans
## add this in application.properties file
management.endpoints.web.exposure.include=*

```

### What is Spring IoC Container?
- Spring IoC container is the program that manages the beans along with the dependencies of those beans(deletion...).
- The Spring IoC container is responsible for instantiating, configuring, and assembling the objects.
- The container gets its instructions on what objects to instantiate, configure, and assemble by reading the configuration metadata provided.
- The configuration metadata can be represented either by XML, Java annotations, or Java code.

### What is Application Context?
- The ApplicationContext is the central interface within a Spring application for providing configuration information to the application.
- It is read-only at runtime, but can be reloaded if necessary and supported by the application.
- Just an implementation of the interface of the Spring IoC container.

### Configuration Metadata(Annotations)
- Annotations are used to provide the configuration metadata to the Spring IoC container.

### Diagram
Configuration Metadata -> Spring IoC Container -> Application Context -> Beans -> Business Objects(POJO) 
                                  |-> Ready to use by the system in our application
### Diagram
```plantuml
@startuml
A[Configuration Metadata] --> B[Spring IoC Container]
B --> C[Application Context]
C --> D[Beans]
D --> E[Business Objects (POJO)]
E --> F[Ready to use by the system in our application]
@enduml
```

### What is Dependency Injection?
- Dependency Injection is a technique where one object supplies the dependencies of another object.
- There are two types of Dependency Injection:
    - Constructor Injection
    - Setter Injection
    - Field Injection
    - Method Injection

### What is the difference between @Component, @Service, @Repository, and @Controller?
- @Component is a generic stereotype for any Spring-managed component.
- @Repository is a stereotype for the persistence layer.
- @Service is a stereotype for the service layer.
- @Controller is a stereotype for the presentation layer (spring-mvc).
- @RestController is a stereotype for the presentation layer (spring-mvc-rest).

### What is the difference between @Component and @Bean?
- @Component is a class level annotation whereas @Bean is a method level annotation and name of the method serves as the bean name.
- @Component is auto-detected by classpath scanning whereas @Bean is explicitly declared in the configuration class.
- @Component is a stereotype annotation whereas @Bean is a method-level annotation.
- @Component is used with classes whereas @Bean is used with methods.

