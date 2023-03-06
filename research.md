# Project Research

---

# MLX introduction

_Info on how to use the 42 MLX graphics library_

## Initialisation

⚠️  MLX need to be initialised at the start of the program using

```c
void    *mlx_ptr;

// Will return NULL if an error occurs !
mlx_ptr = mlx_init()

if (mlx_ptr == NULL)
    // error handling code
```

ℹ️  _mlx_ptr contains all the info needed by the MLX to work, and will be passed
to various MLX functions throughout the program._

## Destruction

_MLX handles display through the X11 graphics API. Before exiting the program,
it is necessary to close the display to avoid leaks._

⚠️  Display must be closed **before** freeing the mlx_ptr.

```c
mlx_destroy_display(mlx_ptr);
free(mlx_ptr);
```

---

# Windows

_Windows are the building block of MLX, there are where you displays information
graphically to the user. You cannot set pixels in the X11 display but you can
set pixels in a window_

```c
void    *window;

// Will return NULL if an error occurs !
window = mlx_new_window(void *mlx_ptr,int size_x,int size_y,char *title);

if (window == NULL)
    // error handling code
```

ℹ️  _Windows are destroyed using the_ **mlx_destroy_window** _function._

---

# Events

* Events are handled through the **mlx_loop** main event loop.
* Events can be registered to the main loops using _event hooks_

⚠️  Main Loop will not run _unless at least one event is registered._

➡️  Use **mlx_loop_hook** to set main loop event.

```c
int		mlx_loop_hook(
    void *mlx_ptr,           // MLX instance
    int (*f)(),              // Callback function
    void *param);            // Parameters passed to callback when called
```

## Hook types

_MLX has general support for X11 events as well as aliases towards specific
functions_

```c
void    mlx_hook(
    mlx_win_list_t *win_ptr, // Window to hook the event to
    int x_event,             // X11 event code
    int x_mask,              // X11 event mask, used to block of events
    int (*f)(),              // Callback function, called when event fires
    void *param)             // Parameters passed to callback when called
```

Hook aliases are:

- mlx_expose_hook: alias to ON_EXPOSE event
- mlx_key_hook: alias to ON_KEYUP event
- mlx_mouse_hook: alias to ON_MOUSEDOWN event

Event callback signatures:

- ON_KEYDOWN / ON_KEYUP
```c
int (*f)(int keycode, void *param)
```

- ON_MOUSEDOWN / ON_MOUSEUP
```c
int (*f)(int button, int x, int y, void *param)
```

- ON_MOUSEMOVE
```c
int (*f)(int x, int y, void *param)
```

- ON_EXPOSE / ON_DESTROY
```c
int (*f)(void *param)
```

---

# Handling display in MLX

_Display in MLX is handled through_ Images. _An image is writen to pixel by
pixel but is displayed as a buffer, that is to say that all the pixels are
displayed ib the screeen at the same time,_ after _they have all been written to
the image._
