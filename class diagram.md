@startuml

class RollingStock {
  - dbId: integer
  - metricGauge: integer
  - metricGrossWeight: integer
  - axleQuantity: integer
  - giveCoupling: boolean
  - acceptCoupling: boolean
}

class LocomotiveModel extends RollingStock {
  - modelName: string
  - engineName: string
  - enginePower: integer
  - fuelType: FuelType
}

class CarModel extends RollingStock {
  - modelName: string
  - carType: CarType
}

class Car {
  - dbId: integer
  - serialNumber: string
  - carModel: CarModel
  - cargos: list<Cargo>
}

class Locomotive {
  - dbId: integer
  - serialNumber: string
  - locomotiveModel: LocomotiveModel
}

class Cargo {
  - dbId: integer
  - description: string
  - weight: float
  - cargoType: CargoType
}

class Composition {
  - dbId: integer
  - locomotives: list<Locomotive>
  - cars: list<Car>
}

class Track {
  - dbId: integer
  - segments: list<Segment>
}

class Waypoint {
  - dbId: integer 
  - xCoordinate: integer
  - yCoordinate: integer
  - locationName: string
}

class Segment {
  - dbId: integer
  - startPoint: Waypoint
  - endPoint: Waypoint
}

class Panel {
  - dbId: integer
  - backgroundImage: string
  - track: Track
  - compositions: list<Composition>
}

enum CarType {
  + FLATBED
  + BOX_WAGON
  + TANKER
  + HOPPER
  + PASSENGER
  + NON_REVENUE
}

enum FuelType {
  + GAS
  + DIESEL
  + ELECTRIC
}

enum CargoType {
  + INERT
  + FLAMMABLE
  + FOOD_GRADE
  + TOXIC
  + EMPTY
  + PASSENGER
}

Car "1..*" -- "1" CarModel
Locomotive "1..*" -- "1" LocomotiveModel
Car "1..*" -- "1..*" Cargo
Composition "1" -- "1..*" Locomotive
Composition "1" -- "1..*" Car
Track "1" -- "1..*" Segment
Segment "1" -- "1" Waypoint
Panel "1" -- "1" Track
Panel "1" -- "0..*" Composition

CarModel "1" *-- "1" CarType
LocomotiveModel "1" *-- "1" FuelType
Cargo "1" *-- "1" CargoType

@enduml
