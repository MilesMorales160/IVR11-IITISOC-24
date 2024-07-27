LIMITED SLIP DIFFERENTIAL
ABSTRACT
This project explores the design and analysis of a comprehensive differential system, incorporating both mechanical and electronic components. The study is divided into three primary phases: the design of a mechanical differential using Fusion 360, the analysis of this design in ANSYS, and the implementation of an electronic differential using the Arduino IDE for Arduino Mega.

In the first phase, the mechanical differential is meticulously designed in Fusion 360, a powerful CAD software that allows for detailed modelling and simulation. This phase focuses on the intricate design elements necessary for a functional differential, ensuring accurate dimensions, tolerances, and assembly features. The design process is documented thoroughly, highlighting the key considerations and decisions made during development.

The second phase involves the analysis of the mechanical differential design using ANSYS, a leading engineering simulation software. This phase aims to evaluate the structural integrity and performance of the differential under various load conditions. Finite Element Analysis (FEA) is employed to identify potential stress points, deformation, and overall durability. The results of the analysis provide crucial insights into the feasibility and reliability of the design, guiding any necessary modifications.

The final phase addresses the implementation of an electronic differential system using Arduino Mega. Leveraging the Arduino IDE, the project develops a control system that dynamically adjusts torque distribution between the wheels based on real-time inputs. This electronic differential enhances the vehicle's handling and stability, offering improved traction and responsiveness. The programming aspects, sensor integration, and actuator control are detailed, demonstrating the capabilities and advantages of an electronic approach over traditional mechanical systems.

Overall, this project presents a comprehensive approach to differential system design and analysis, combining advanced CAD modelling, rigorous simulation, and innovative electronic control. The findings contribute valuable knowledge to the fields of mechanical and electronic engineering, with potential applications in automotive design and other industries requiring precise torque management and stability control.
INTRODUCTION
In the realm of automotive engineering, the differential is a crucial component that allows for the smooth and efficient transfer of power from the engine to the wheels. Among the various types of differentials, the Limited Slip Differential (LSD) stands out for its ability to provide better traction and stability, especially under adverse driving conditions. This feature is particularly valuable in high-performance and off-road vehicles, where maintaining control and optimizing power distribution are essential.

The concept of the Limited Slip Differential was developed to address the limitations of the conventional open differential, which can cause wheel spin and loss of traction when one wheel encounters a slippery surface. By limiting the slip between the wheels, an LSD ensures that power is distributed more evenly, thereby enhancing the vehicle's handling and performance.

There are primarily two types of LSDs: mechanical and electronic. Mechanical LSDs rely on clutches, gears, or viscous fluids to control wheel slip. While effective, these systems can be complex and wear over time. On the other hand, electronic LSDs utilize sensors and actuators to dynamically adjust the torque distribution between the wheels. This not only provides a more responsive and adaptable system but also integrates seamlessly with modern vehicle stability and traction control systems.

The objective of this project is to design and build an electronic Limited Slip Differential. This involves understanding the underlying principles of LSDs, comparing mechanical and electronic systems, and ultimately developing a functional prototype. By exploring this innovative approach, the project aims to contribute to the advancement of vehicle dynamics and safety technologies.

METHODOLOGY
DIFFERENTIAL GEARS DESIGN:
The major part of the mechanical differential are the differential gears. We have decided to take the crown and pinion gear with a spiral bevel gear design to ensure to have a high torque and minimal power loss between these two gears. The following is the procedure we followed for this design.
1. Define Gear Parameters
•	Module (m): The module of the gear, which defines the size of the teeth.
•	Number of Teeth (Z): The number of teeth on the gear.
•	Pressure Angle (α): The angle between the line of action and the common tangent to the pitch circles.
•	Pitch Diameter (d): Calculated using the formula d=m×Zd = m \times Zd=m×Z.
•	Cone Angle (γ): For bevel gears, this angle depends on the gear ratio.
2. Define the Tooth Profile
•	According to the design calculations take two tooth profile of spur gears and define the spiral shape we need for the certain angle.
•	Then using loft create a spiral bevel gear tooth.
•	Use the circular pattern tool to replicate the tooth around the pitch circle.
3. Extrude the Gear Blank
•	Then according to bevel gear cone angle make the gear body by revolving a trapezium that fit before the gear teeth.
4. Assemble the Gears
•	Create another bevel gear following the same steps, adjusting the gear ratio and cone angles as required.
•	Assemble the gears to check the meshing and alignment.
•	Use the joint feature in Fusion 360 to simulate the gear interaction.
For the side gear and spider gear design we chose simple bevel gears. We followed the below procedure for this.
1. Define Gear Parameters
•	Module (m): The module of the gear, which defines the size of the teeth.
•	Number of Teeth (Z): The number of teeth on the gear.
•	Pressure Angle (α): The angle between the line of action and the common tangent to the pitch circles.
•	Pitch Diameter (d): Calculated using the formula d=m×Zd = m \times Zd=m×Z.
•	Cone Angle (γ): For bevel gears, this angle depends on the gear ratio.
2. Define the Tooth Profile
•	According to the design calculations take two tooth profile of spur gears and use it loft to get the bevel gear tooth.
•	Use the circular pattern tool to replicate the tooth around the pitch circle.
3. Extrude the Gear Blank
•	Then according to bevel gear cone angle make the gear body by revolving a trapezium that fit before the gear teeth.
4. Assemble the Gears
•	Create another bevel gear following the same steps, adjusting the gear ratio and cone angles as required.
•	Assemble the gears to check the meshing and alignment.

For the designing the differential gears (Bevel gears) I have followed the following reference from Youtube for the calculations of the gear design.

https://youtu.be/ot_RpfjxvsM?si=sU6fgMV8njTynKhb

DESIGNING OF OTHER IMPORTANT PARTS:
1. Shell Housing
1.	Define Dimensions:
o	Determine overall dimensions: diameter, height, wall thickness, and any mounting features.
2.	Create Base Sketch:
o	Start a new sketch on the XY plane.
o	Draw the outer and inner circles representing the shell’s outer and inner diameters.
3.	Extrude:
o	Extrude the base sketch to the desired height to create the cylindrical housing.
4.	Detail Features:
o	Add features such as mounting holes, ribs for structural integrity, and slots or grooves for components like friction and steel plates.
5.	Finish and Fillet:
o	Apply fillets to edges to reduce stress concentrations and enhance manufacturability.

2. Friction Plate
1.	Define Dimensions:
o	Determine outer and inner diameters, thickness.
2.	Create Base Sketch:
o	Start a new sketch on the XY plane.
o	Draw the outer and inner circles.
3.	Extrude:
o	Extrude the sketch to the required thickness.
4.	Detail Features:
o	Add teeth or tabs along the inner or outer edge to interlock with the LSD hub or shell housing.
o	Create slots or perforations if needed for better friction characteristics.
3. Pressure Plate
1.	Define Dimensions:
o	Determine the diameter, thickness.
2.	Create Base Sketch:
o	Start a new sketch on the XY plane.
o	Draw the outer circle and any inner features.
3.	Extrude:
o	Extrude the sketch to the required thickness.
4.	Detail Features:
o	Add any necessary features such as spring pockets, grooves, or ribs for load distribution.
o	Apply fillets and chamfers to reduce stress concentrations.
4. LSD Hub
1.	Define Dimensions:
o	Determine overall dimensions, including diameters, length, and any features for interlocking with other components.
2.	Create Base Sketch:
o	Start a new sketch on the XY plane.
o	Draw the cross-sectional profile of the hub.
3.	Extrude:
o	Extrude the sketch to the required length.
4.	Detail Features:
o	Add keyways, splines, or teeth for engaging with the friction and steel plates.
o	Create any necessary mounting features or holes.
5.	Finish:
o	Apply fillets and chamfers to enhance manufacturability and reduce stress concentrations.
5. Steel Plate
1.	Define Dimensions:
o	Determine outer and inner diameters, thickness, and any specific design features.
2.	Create Base Sketch:
o	Start a new sketch on the XY plane.
o	Draw the outer and inner circles.
3.	Extrude:
o	Extrude the sketch to the required thickness.
4.	Detail Features:
o	Add any necessary teeth, tabs, or slots for engagement with the LSD hub or shell housing.
6. LSD Pin
1.	Define Dimensions:
o	Determine the length, diameter, and any specific features like holes or notches.
2.	Create Base Sketch:
o	Start a new sketch on the XY plane.
o	Draw the cross-sectional profile of the pin.
3.	Extrude:
o	Extrude the sketch to the required length.
4.	Detail Features:
o	Add any holes, grooves, or notches as necessary for the pin’s function.
7.Bearings
      • Outer Ring:
•	Sketch: Outer and inner circles.
•	Extrude: To required width.
•	Features: Add raceway grooves, fillets.
• Inner Ring:
•	Sketch: Inner and outer circles.
•	Extrude: To required width.
•	Features: Add raceway grooves, fillets.
• Balls:
•	Sketch: Circle with ball diameter.
•	Extrude: To create a cylinder.
•	Pattern: Circular pattern around inner ring.


ANALYZING USING THE ANSYS SOFTWARE:
Analysis

The analysis of the parts is done using FEM techniques in Ansys Workbench 2024R1 and Ansys Mechanical 2024R2. The chosen material for the parts is 20MnCr5 alloy with the following properties
Name of the alloy: 20MnCr5
Model type: Linear elastic isotropic
Yield Strength:850 MPa
Tensile Strength:1300 Mpa
Elastic Modulus:2E + 5 Mpa
Poisson’s Ratio:0.285
Shear Modulus:7.7821E+4 Mpa
Bulk Modulus:1.5504E+5 Mpa

After choosing static structural option in Workbench and choosing Model option which will direct us to Mechanical Following steps are involved in analysis of crown and pinion gear system,
1)	Meshing of the bodies in default settings
2)	Fixed support is Given to the pinion gear and Frictionless support is given to Crown Gear
3)	Displacement property is given to both Pinion and Crown gears restricting its motion along Y axis and Z axis respectively
4)	A moment of 9.55 N-m is Given to the Pinion Gear which is calculated from the following equation: (60 * 10^6 * Kw)/ (2 * π * Np)    Where, Input power (kw) = 5, Np = 5000 RPM
5)	The solutions are obtained for Total Deformation, Equivalent Stress, Safety factor

References
•	https://www.youtube.com/watch?v=A7U76REZvmg&t=271s&pp=ygUTYmV2ZWwgZ2VhciBhbmFseXNpcw%3D%3D
•	https://journal.utem.edu.my/index.php/jmet/article/viewFile/3969/3977
•	https://www.irjmets.com/uploadedfiles/paper/volume3/issue_1_january_2021/5876/1628083241.pdf
•	https://youtu.be/921ToiOynMA
•	https://www.scribd.com/document/650337936/Vernier-depth-gauge

CHALLENGES FACED:
We especially faced challenges and learnt many things while assembling the gears.

CONTRIBUTIONS
VIGNESWAR: Gear design, code for Electronic Differential.
NISANTH: Design of differential  gear housing, housing, steel plate, friction plate, pressure plates, hub, pin. Overall assembly of the model.Gave a support to teammate to do ansys simulations.
NIHAL: FEA, Assembly of the gears into the overall assembly.
PRAVEEN: Bearings, Getting resources and Documentation.

References:
Google resources (uploaded in git), Youtube (links provided previosly, chatgpt for doubts. 
For assembly we have referred the following video.
https://youtu.be/1jbkHboGHNo?si=QPWkMYaLSTDH80Hw


