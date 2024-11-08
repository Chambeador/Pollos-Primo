import os

# Carpeta raíz de tu teambook
root_folder = "."  # Cambia si necesitas especificar otra ubicación
output_file = "teambook.tex"

# Crear el archivo principal de LaTeX
with open(output_file, "w") as f:
    # Encabezado de LaTeX para formato visual
    f.write(r"""\documentclass{article}
\usepackage{listings}
\usepackage{xcolor}
\usepackage{amsmath}
\usepackage{geometry}
\usepackage{titlesec}
\geometry{margin=1in}

% Configuración de colores y estilo de código
\definecolor{commentgreen}{rgb}{0.25, 0.5, 0.35}
\definecolor{keywordblue}{rgb}{0.2, 0.2, 0.7}
\definecolor{stringorange}{rgb}{0.8, 0.4, 0.1}

\lstset{
    language=C++,
    basicstyle=\ttfamily\small,
    keywordstyle=\color{keywordblue}\bfseries,
    commentstyle=\color{commentgreen}\itshape,
    stringstyle=\color{stringorange},
    breaklines=true,
    frame=single,
    numbers=left,
    numberstyle=\tiny\color{gray},
    showspaces=false,
    showstringspaces=false,
    captionpos=b,
}

% Personalización de títulos
\titleformat{\section}{\normalfont\Large\bfseries}{\thesection}{1em}{}
\titleformat{\subsection}{\normalfont\large\bfseries}{\thesubsection}{1em}{}

\begin{document}
\title{Team Notebook}
\author{Equipo de Programación}
\date{\today}
\maketitle
\tableofcontents
\newpage
""")

    # Recorrer todas las carpetas y archivos
    for dirpath, dirnames, filenames in os.walk(root_folder):
        # Añadir cada carpeta como una sección en LaTeX
        if dirpath != root_folder:
            section_name = os.path.basename(dirpath)
            f.write(f"\\section{{{section_name}}}\n")

        # Añadir cada archivo .cpp como un subapartado en LaTeX
        for filename in sorted(filenames):
            if filename.endswith(".cpp"):
                filepath = os.path.join(dirpath, filename)
                subsection_name = os.path.splitext(filename)[0]
                f.write(f"\\subsection{{{subsection_name}}}\n")
                f.write(f"\\lstinputlisting[title={subsection_name}]{{{filepath}}}\n\n")

    # Cerrar el documento de LaTeX
    f.write("\\end{document}")
