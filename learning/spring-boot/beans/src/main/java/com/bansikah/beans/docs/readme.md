### Beans
- A bean is a class that has some metadata attached to it
- Beans are managed by the Spring IoC container
- They can be instantiated, assembled, and managed by Spring
- Beans can be singleton or prototype scoped
- They are defined in the Spring configuration file or annotated with `@Component`, `@Service`, `@Repository`, or `@Controller`

### IOC(Inversion of control)
- Inversion of control (IoC) is a design principle in which the control of object creation and management is transferred to a container or framework.
- In Spring, the IoC container is responsible for instantiating, configuring, and managing the lifecycle of beans.
- IoC allows for better separation of concerns and decoupling of components.
- It enables easier testing and maintenance of code by promoting dependency injection.
- Instead of creating instances using the `new` keyword, Spring handles the creation and injection of dependencies.
